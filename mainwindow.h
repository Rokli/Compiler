#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <Models/document.h>
#include <referencewindow.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void createDocument();
    void openDocument();
    void saveDocument();
    void saveAsDocument();
    void exitDocument();

    void ovverideEditing();
    void copyEditing();
    void cutEditing();
    void insertEditing();
    void removeEditing();
    void replaceEditing();
    void selectAllEditing();

    void callReference();
    void aboutReference();

private:
    Ui::MainWindow *ui;
    Document *document_;

};
#endif // MAINWINDOW_H
