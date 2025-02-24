#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <Models/document.h>
#include <QDesktopServices>
#include <QUrl>
#include<QTabWidget>
#include <QToolBar>
#include <QMimeData>
#include <QUrl>
#include "Models/codeeditor.h"

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

    void openSettings();

    void closeTab(int index);
    void addNewTab();
    void closeCurrentTab();

    void updateCursorPosition();
    void updateTabName(int index);

    CodeEditor* getCurrentIdTextEdit();
    CodeEditor* getTextEdit(int id);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
private:
    Ui::MainWindow *ui;
    int current_id_;
    Document *document_;

};
#endif // MAINWINDOW_H
