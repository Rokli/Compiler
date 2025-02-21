#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    document_ = new Document("new_document.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDocument(){
    document_->create(ui->textDocument);
}

void MainWindow::openDocument(){
    document_->open(ui->textDocument);
}

void MainWindow::saveDocument(){
    document_->save(ui->textDocument);
}

void MainWindow::saveAsDocument(){
    document_->saveAs(ui->textDocument);
}

void MainWindow::exitDocument(){
    document_->exit(ui->textDocument);
    QApplication::quit();
}

void MainWindow::ovverideEditing(){
    ui->textDocument->undo();
}

void MainWindow::copyEditing(){
    ui->textDocument->copy();
}

void MainWindow::cutEditing(){
    ui->textDocument->cut();
}

void MainWindow::insertEditing(){
    ui->textDocument->paste();
}

void MainWindow::removeEditing(){
    ui->textDocument->textCursor().removeSelectedText();
}

void MainWindow::replaceEditing(){
    ui->textDocument->redo();
}

void MainWindow::selectAllEditing(){
    ui->textDocument->selectAll();
}
