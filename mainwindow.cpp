#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setAcceptDrops(true);
    ui->setupUi(this);
    document_ = new Document("new_document.txt");

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

    QTabWidget *tabWidget = ui->tabWidget;

    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->setMovable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);

    QToolBar *toolBar = addToolBar("Файл");
    QAction *newTabAction = new QAction("Новая вкладка", this);
    QAction *closeTabAction = new QAction("Закрыть вкладку", this);

    connect(newTabAction, &QAction::triggered, this, &MainWindow::addNewTab);
    connect(closeTabAction, &QAction::triggered, this, &MainWindow::closeCurrentTab);

    toolBar->addAction(newTabAction);
    toolBar->addAction(closeTabAction);
    addNewTab();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDocument(){
    document_->create(getCurrentIdTextEdit());
}

void MainWindow::openDocument(){
    // document_->open(ui->textDocument);
}

void MainWindow::saveDocument(){
    // document_->save(ui->textDocument);
}

void MainWindow::saveAsDocument(){
    // document_->saveAs(ui->textDocument);
}

void MainWindow::exitDocument(){
    // document_->exit(ui->textDocument);
    QApplication::quit();
}

void MainWindow::ovverideEditing(){
    // ui->textDocument->undo();
}

void MainWindow::copyEditing(){
    //ui->textDocument->copy();
}

void MainWindow::cutEditing(){
    // ui->textDocument->cut();
}

void MainWindow::insertEditing(){
     //ui->textDocument->paste();
}

void MainWindow::removeEditing(){
    // ui->textDocument->textCursor().removeSelectedText();
}

void MainWindow::replaceEditing(){
    // ui->textDocument->redo();
}

void MainWindow::selectAllEditing(){
    // ui->textDocument->selectAll();
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
    // if(event->modifiers() & Qt::ControlModifier){
    //     int delta = event->angleDelta().y();
    //     QFont fontTextDocument = ui->textDocument->font();

    //     int newSize = fontTextDocument.pointSize() + (delta > 0 ? 1 : -1);
    //     if (newSize >= 8 && newSize <= 32) {
    //         fontTextDocument.setPointSize(newSize);
    //         ui->textDocument->setFont(fontTextDocument);
    //         ui->console->setFont(fontTextDocument);
    //     }
    //     event->accept();
    // }
}

void MainWindow::closeTab(int index){
    if (ui->tabWidget->count() > 1) {
        QWidget *widget = ui->tabWidget->widget(index);
        ui->tabWidget->removeTab(index);
        delete widget;
    } else {
        QMessageBox::warning(this, "Предупреждение", "Нельзя закрыть последнюю вкладку!");
    }
}

int MainWindow::addNewTab(){
    CodeEditor *textEdit = new CodeEditor(this);
    int index = ui->tabWidget->addTab(textEdit, "Новая вкладка");
    ui->tabWidget->setCurrentIndex(index);
    return index;
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

    int index = addNewTab();

    QString filePath = urls.first().toLocalFile();
    CodeEditor *editor = qobject_cast<CodeEditor*>(ui->tabWidget->widget(index));

    document_->open(filePath,editor);
}

CodeEditor* MainWindow::getCurrentIdTextEdit(){
    return qobject_cast<CodeEditor*>(ui->tabWidget->widget(ui->tabWidget->currentIndex()));
}

void MainWindow::updateCursorPosition(){

}

