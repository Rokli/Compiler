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

    connect(ui->statmentProblem,&QAction::triggered,this,&MainWindow::aboutStateMentProblem);
    connect(ui->classificationGrammar,&QAction::triggered,this,&MainWindow::aboutClassificationGrammar);
    connect(ui->diagnosticsAnalysisError,&QAction::triggered,this,&MainWindow::aboutDiagnosticsAnalysisError);
    connect(ui->grammar,&QAction::triggered,this,&MainWindow::aboutGrammar);
    connect(ui->references,&QAction::triggered,this,&MainWindow::aboutReferences);
    connect(ui->sourceCodeProgramm,&QAction::triggered,this,&MainWindow::aboutSourceCodeProgramm);
    connect(ui->testCase,&QAction::triggered,this,&MainWindow::aboutTestCase);

    QString appDir = QCoreApplication::applicationDirPath();

    QIcon icon(":/icons/copy.png");
    if (icon.isNull()) {
        qWarning() << "Иконка не загрузилась!";
    }
    ui->copyButton->setIcon(icon);
    QDirIterator it(":/icons", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qWarning() << "Найден ресурс:" << it.next();
    }
    qWarning() << "Найден ресурс:";
    ui->copyButton->setIcon(QIcon(":/icons/icons/copy.png"));
    ui->createDocumentButton->setIcon(QIcon(":/icons/icons/create_document.png"));
    ui->cutButton->setIcon(QIcon(":/icons/icons/cut.png"));
    ui->insertButton->setIcon(QIcon(":/icons/icons/insert.png"));
    ui->openDocumentButton->setIcon(QIcon(":/icons/icons/open_document.png"));
    ui->ovverideButton->setIcon(QIcon(":/icons/icons/arrow-left.png"));
    ui->replaceButton->setIcon(QIcon(":/icons/icons/arrow-right.png"));
    ui->saveDocumentButton->setIcon(QIcon(":/icons/icons/save_document.png"));
    changeTheme();
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

void MainWindow::aboutStateMentProblem(){
    QMessageBox::information(this,
                             "Постановка задачи",
                             "Выполнить программную реализацию объявления функции define на языке PHP.");
}

void MainWindow::aboutClassificationGrammar(){
    QMessageBox::information(this,
                            "Классификация грамматики",
                            "Автоматные или регулярные грамматики имеют самые строгие ограничения на форму записи правил:\n"
                            "A → aB | a | ε,"
                            "где a∈VТ, A∈VN и B∈VB.");
}

void MainWindow::aboutDiagnosticsAnalysisError(){
    QMessageBox::information(this,
                            "Диагностика и нейтрализация ошибок\n",
                            "Алгоритм нейтрализации состоит из следующих шагов:\n"
                            "1. Определяются недостроенные кусты дерева разбора;\n"
                            "2. Формируется множество L – множество остаточных символов недостроенных кустов дерева разбора;\n"
                            "3. Из входной цепочки удаляется следующий символ до тех пор, пока цепочка не примет вид Tt, такой, что U => T, где U ∈ L, то есть до тех пор, пока следующий в цепочке символ T не сможет быть выведен из какогонибудь из остаточных символов недостроенных кустов.\n"
                            "4. Определяется, какой из недостроенных кустов стал причиной появления символа U в множестве L (иначе говоря, частью какого из недостроенных кустов является символ U)");
}

void MainWindow::aboutGrammar(){
    QMessageBox::information(this,
                            "Грамматика",
                            "1. <DEF> -> 'define' <LPAREN>\n"
                            "2. <LPAREN> -> '(' <MARK>\n"
                            "3. <MARK> -> '\"' <ID>\n"
                            "4. <ID> -> letter <IDREM>\n"
                            "5. <ID> -> digit <IDREM>\n"
                            "6. <IDREM> -> letter <IDREM>\n"
                            "7. <IDREM> -> digit <IDREM>\n"
                            "8. <IDREM> -> '\"' <COMMA>\n"
                            "9. <COMMA> -> ',' <VALUE>\n"
                            "10.  <VALUE> -> digit <VALUEREM>\n"
                            "11.  <VALUE> -> '\"' <STRING>\n"
                            "12.  <VALUE> -> 'true' <RPAREN>\n"
                            "13.  <VALUE> -> 'false' <RPAREN>\n"
                            "14.  <VALUE> -> '+' <VALUETYPE>\n"
                            "15.  <VALUE> -> '-' <VALUETYPE>\n"
                            "16.  <VALUETYPE> -> digit <VALUEREM>\n"
                            "17.  <VALUEREM> -> digit <VALUEREM>\n"
                            "18.  <VALUEREM> -> ')' <SEMICOLON>\n"
                            "19.  <VALUEREM> -> '.' <DECIMAL>\n"
                            "20.  <DECIMAL> -> digit <DECIMALREM>\n"
                            "21.  <DECIMALREM> -> digit <DECIMALREM>\n"
                            "22.  <DECIMALREM> -> \")\" <SEMILICON>\n"
                            "23.  <STRING> -> letter <STRINGREM>\n"
                            "24.  <STRING> -> digit <STRINGREM>\n"
                            "25.  <STRINGREM> -> letter <STRINGREM>\n"
                            "26.  <STRINGREM> -> digit <STRINGREM>\n"
                            "27.  <STRINGREM> -> '\"' <RPAREN>\n"
                            "28.  <RPAREN> -> ')' <SEMICOLON>\n"
                            "29.  <SEMICOLON> -> ';'\n"
                            "<letter> → 'a' | 'b' | 'c' | ... | 'z' | 'A' | 'B' | 'C' | ... | 'Z' |\n"
                            "<digit> → '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'\n"
                            "Следуя введенному формальному определению грамматики, представим G[<DEF>] ее составляющими:\n"
                            "• Z = G[<DEF >];\n"
                            "• VT = {a, b, c, ..., z, A, B, C, ..., Z, +, -, ;, .,0, 1, 2, ..., 9};\n"
                            "• VN = {<DEF>, <LPAREN>, <MARK>, <ID>, <IDREM>,   <COMMA>, <VALUE>, <VALUETYPE>, <VALUEREM>, <DECIMAL>, <DECIMALREM>, <STRING>, <STRINGREM>, <RPAREN>, <SEMICOLON>}\n");
}
void MainWindow::aboutReferences(){
    QMessageBox::information(this,
                            "Список литературы",
                            "1. Теория формальных языков и компиляторов [Электронный ресурс]/ Электрон. дан. URL: https://dispace.edu.nstu.ru/didesk/course/show/8594, свободный. Яз.рус. (дата обращения 19.03.2025).\n"
                            "2. Gries D. Designing Compilers for Digital Computers. New York, Jhon Wiley, 1971. 493 p.\n"
                            "3. Основы PHP\Константы [Электронный ресурс]/ Электрон. дан.\n"
                            "URL: https://metanit.com/php/tutorial/2.4.php, свободный. Яз.рус. (дата обращения 20.03.2025).\n"
                            "4. Шорников Ю.В. Теория и практика языковых процессоров : учеб. пособие / Ю.В. Шорников. – Новосибирск: Изд-во НГТУ, 2004.");
}

void MainWindow::aboutSourceCodeProgramm(){
    QMessageBox::information(this,
                             "Исходный код программы",
                             "https://github.com/Rokli/Compiler");
}

void MainWindow::aboutTestCase(){
    if(!checkWork()) return;
    getCurrentIdTextEdit()->setPlainText("define(\"VALUE\",30.3);");
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
    //5
    // ExpressionParser parser(getCurrentIdTextEdit()->toPlainText());
    // parser.analyze(ui->tableWidget);
    //6
    PatternMatcher matcher(getCurrentIdTextEdit()->toPlainText());

    matcher.findUSZipCodes(ui->tableWidget);              // Для задачи 2
    // matcher.findYearsInRange(ui->tableWidget);         // Для задачи 18
    // matcher.findRealNumbersWithExponent(ui->tableWidget); // Для задачи 20
}

void MainWindow::openSettings(){

}
