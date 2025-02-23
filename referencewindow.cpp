#include "referencewindow.h"
#include "ui_referencewindow.h"

ReferenceWindow::ReferenceWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReferenceWindow)
{
    ui->setupUi(this);
    setWindowTitle("Справка");
}

ReferenceWindow::~ReferenceWindow()
{
    delete ui;
}
