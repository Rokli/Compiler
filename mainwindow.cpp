#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setAcceptDrops(true);
    ui->setupUi(this);
    document_ = new Document("new_document.txt");
    theme_ = new StyleTheme();
    lexer_ = new LexerPhp(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QTabWidget *tabWidget = ui->tabWidget;

    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->setMovable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);
    current_id_ = 0;

    ui->createDocumentButton->setToolTip("Создать документ");
    ui->openDocumentButton->setToolTip("Открыть документ");
    ui->insertButton->setToolTip("Вставить текст");
    ui->copyButton->setToolTip("Скопировать текст");
    ui->ovverideButton->setToolTip("Отменить последнее изменение");
    ui->replaceButton->setToolTip("Повторить последнее изменение");
    ui->saveDocumentButton->setToolTip("Сохранить документ");
    ui->cutButton->setToolTip("Вырезать текст");

    connect(ui->create, &QAction::triggered, this, &MainWindow::createDocument);
    connect(ui->open, &QAction::triggered, this, &MainWindow::openDocument);
    connect(ui->save, &QAction::triggered, this, &MainWindow::saveDocument);
    connect(ui->saveAs, &QAction::triggered, this, &MainWindow::saveAsDocument);
    connect(ui->exit, &QAction::triggered, this, &MainWindow::exitDocument);

    connect(ui->ovveride,&QAction::triggered,this,&MainWindow::ovverideEditing);
    connect(ui->copy,&QAction::triggered,this,&MainWindow::copyEditing);
    connect(ui->cut,&QAction::triggered,this,&MainWindow::cutEditing);
    connect(ui->insert,&QAction::triggered,this,&MainWindow::insertEditing);
    connect(ui->remove,&QAction::triggered,this,&MainWindow::removeEditing);
    connect(ui->replace,&QAction::triggered,this,&MainWindow::replaceEditing);
    connect(ui->select_all,&QAction::triggered,this,&MainWindow::selectAllEditing);

    connect(ui->callReference,&QAction::triggered,this,&MainWindow::callReference);
    connect(ui->aboutReference,&QAction::triggered,this,&MainWindow::aboutReference);

    connect(ui->createDocumentButton,&QPushButton::clicked,this,&MainWindow::createDocument);
    connect(ui->openDocumentButton,&QPushButton::clicked,this,&MainWindow::openDocument);
    connect(ui->saveDocumentButton,&QPushButton::clicked,this,&MainWindow::saveDocument);
    connect(ui->ovverideButton,&QPushButton::clicked,this,&MainWindow::ovverideEditing);
    connect(ui->replaceButton,&QPushButton::clicked,this,&MainWindow::replaceEditing);
    connect(ui->copyButton,&QPushButton::clicked,this,&MainWindow::copyEditing);
    connect(ui->cutButton,&QPushButton::clicked,this,&MainWindow::cutEditing);
    connect(ui->insertButton,&QPushButton::clicked,this,&MainWindow::insertEditing);

    connect(ui->command, &QMenu::aboutToShow, this, &MainWindow::command);

    connect(ui->changeLang,&QAction::triggered,this,&MainWindow::changeLanguage);
    connect(ui->changeTheme,&QAction::triggered,this,&MainWindow::changeTheme);
    connect(ui->customizeFont,&QAction::triggered,this,&MainWindow::customizeFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDocument(){
    addNewTab();
    document_->create(getTextEdit(current_id_));
    updateTabName(current_id_);
}

void MainWindow::openDocument(){
    addNewTab();
    document_->open(getTextEdit(current_id_));
    updateTabName(current_id_);
}

void MainWindow::saveDocument(){
    if(!checkWork()) return;
    document_->save(getTextEdit(current_id_));
    closeTab(current_id_);
}

void MainWindow::saveAsDocument(){
    if(!checkWork()) return;
    addNewTab();
    document_->saveAs(getTextEdit(current_id_));
    updateTabName(current_id_);
}

void MainWindow::exitDocument(){
    document_->exit(getTextEdit(current_id_));
    QApplication::quit();
}

void MainWindow::ovverideEditing(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->undo();
}

void MainWindow::copyEditing(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->copy();
}

void MainWindow::cutEditing(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->cut();
}

void MainWindow::insertEditing(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->paste();
}

void MainWindow::removeEditing(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->textCursor().removeSelectedText();
}

void MainWindow::replaceEditing(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->redo();
}

void MainWindow::selectAllEditing(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->selectAll();
}

void MainWindow::callReference(){
    QString path = QCoreApplication::applicationDirPath() + "/documentation/documentation.html";
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

void MainWindow::aboutReference(){
    QMessageBox::information(this,
                             "О программе",
                             "Приложение создана студентом НГТУ Шаталов Максимом.\n"
                             "Приложение создана для того, что бы запускать функции инициализации константы define() языка PHP.\n"
                             "О установке и управлении приложения можно почитать в документации.");
}

void MainWindow::openSettings(){

}

void MainWindow::wheelEvent(QWheelEvent *event){
    CodeEditor* editor = getCurrentIdTextEdit();
    if(event->modifiers() & Qt::ControlModifier){
        int delta = event->angleDelta().y();
        QFont fontTextDocument = editor->font();

        int newSize = fontTextDocument.pointSize() + (delta > 0 ? 1 : -1);
        if (newSize >= 8 && newSize <= 32) {
            fontTextDocument.setPointSize(newSize);
            editor->setFont(fontTextDocument);
        }
        event->accept();
    }
}

void MainWindow::closeTab(int index){
    QWidget *widget = ui->tabWidget->widget(index);
    ui->tabWidget->removeTab(index);
    delete widget;
}

void MainWindow::addNewTab(){
    CodeEditor *textEdit = new CodeEditor(this);
    lexer_->setDocument(textEdit->document());
    connect(textEdit, &QPlainTextEdit::textChanged, this, &MainWindow::onTextChanged);
    current_id_ = ui->tabWidget->addTab(textEdit,"Новый документ");
    ui->tabWidget->setCurrentIndex(current_id_);
}

void MainWindow::closeCurrentTab(){
    closeTab(ui->tabWidget->currentIndex());
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event){
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty()) return;

    QString filePath = urls.first().toLocalFile();
    CodeEditor *editor = qobject_cast<CodeEditor*>(ui->tabWidget->widget(current_id_));

    document_->open(filePath,editor);
}

CodeEditor* MainWindow::getCurrentIdTextEdit(){
    return qobject_cast<CodeEditor*>(ui->tabWidget->widget(ui->tabWidget->currentIndex()));
}

CodeEditor* MainWindow::getTextEdit(int id){
    return qobject_cast<CodeEditor*>(ui->tabWidget->widget(id));
}
void MainWindow::updateCursorPosition(){

}

void MainWindow::updateTabName(int index){
    QString fileName = document_->getFileName();
    if (!fileName.isEmpty()) {
        ui->tabWidget->setTabText(index, fileName);
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (isModified_) {
        QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Программа",
                                                                   "Сохранить изменения?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
                                                                   QMessageBox::Save);
        if (resBtn == QMessageBox::Save) {
            saveDocument();
            event->accept();
        } else if (resBtn == QMessageBox::Discard) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}

void MainWindow::onTextChanged(){
    isModified_ = true;
}

void MainWindow::changeLanguage(){
    language_ = language_ ? false : true;

    if(language_){
        ui->menuFile->setTitle("Файл");
        ui->create->setText("Создать");
        ui->open->setText("Открыть");
        ui->save->setText("Сохранить");
        ui->saveAs->setText("Сохранить как");
        ui->exit->setText("Выход");

        ui->menuFile->setTitle("Правка");
        ui->ovveride->setText("Отменить");
        ui->replace->setText("Повторить");
        ui->cut->setText("Вырезать");
        ui->copy->setText("Копировать");
        ui->insert->setText("Вставить");
        ui->remove->setText("Удалить");
        ui->select_all->setText("Выделить все");

        ui->menuText->setTitle("Текст");
        ui->analysisMethod->setText("Метод анализа");
        ui->classificationGrammar->setText("Классификация грамматики");
        ui->diagnosticsAnalysisError->setText("Диагностика и нейтрализация ошибок");
        ui->grammar->setText("Грамматика");
        ui->references->setText("Список литературы");
        ui->sourceCodeProgramm->setText("Исходный код программы");
        ui->statmentProblem->setText("Постановка задачи");
        ui->testCase->setText("Тестовый пример");

        ui->settings->setTitle("Настройки");
        ui->customizeFont->setText("Настроить шрифт");
        ui->changeLang->setText("Настроить язык");
        ui->changeTheme->setText("Сменить тему");

        ui->reference->setTitle("Справка");
        ui->callReference->setText("Вызов справки");
        ui->aboutReference->setText("О программе");

        ui->command->setTitle("Пуск");
        QStringList headers = {"Путь к файлу", "Линия", "Сообщение"};
        ui->tableWidget->setHorizontalHeaderLabels(headers);
    }
    else{
        ui->menuFile->setTitle("File");
        ui->create->setText("Create");
        ui->open->setText("Open");
        ui->save->setText("Save");
        ui->saveAs->setText("Save as");
        ui->exit->setText("Exit");

        ui->menuEditor->setTitle("Editing");
        ui->ovveride->setText("Ovveride");
        ui->replace->setText("Replace");
        ui->cut->setText("Cut");
        ui->copy->setText("Copy");
        ui->insert->setText("Insert");
        ui->remove->setText("Remove");
        ui->select_all->setText("Select all");

        ui->menuText->setTitle("Text");
        ui->analysisMethod->setText("Analysis method");
        ui->classificationGrammar->setText("Classification grammar");
        ui->diagnosticsAnalysisError->setText("Diagnostics and analysis error");
        ui->grammar->setText("Grammar");
        ui->references->setText("References");
        ui->sourceCodeProgramm->setText("Source code programm");
        ui->statmentProblem->setText("Statment problem");
        ui->testCase->setText("Test case");

        ui->settings->setTitle("Settings");
        ui->customizeFont->setText("Customize font");
        ui->changeLang->setText("Change language");
        ui->changeTheme->setText("Change theme");

        ui->reference->setTitle("Reference");
        ui->callReference->setText("Call reference");
        ui->aboutReference->setText("About programm");

        ui->command->setTitle("Command");

        QStringList headers = {"File path", "Line", "Message"};
        ui->tableWidget->setHorizontalHeaderLabels(headers);
    }
}

void MainWindow::customizeFont(){
    QMessageBox::information(this,
                             "Изменения шрифта",
                             "ctrl+MouseWheel");
}

bool MainWindow::checkWork(){
    if(!current_id_) return true;
    else return false;
}

void MainWindow::changeTheme(){
    if(!theme_->theme_){
        setStyleSheet(theme_->ligthTheme_);
        theme_->theme_ = true;
    }
    else{
        setStyleSheet(theme_->darkTheme_);
        theme_->theme_ = false;
    }
}

void MainWindow::command(){
    LexicalScanner lexer(getCurrentIdTextEdit()->toPlainText());
    lexer.analyzeToTable(ui->tableWidget);
}
