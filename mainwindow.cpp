#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //document
    connect(ui->create, &QAction::triggered, this, &MainWindow::createDocument);
    connect(ui->open, &QAction::triggered, this, &MainWindow::openDocument);
    connect(ui->save, &QAction::triggered, this, &MainWindow::saveDocument);
    connect(ui->saveAs, &QAction::triggered, this, &MainWindow::saveAsDocument);
    connect(ui->exit, &QAction::triggered, this, &MainWindow::exitDocument);
    //
    //
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
