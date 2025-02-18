#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QFile>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QWidget>
#include <QTextStream>

class Document
{
public:
    Document(QString name_file  = "new_document.txt");
    void create(QPlainTextEdit* editor);
    void open(QPlainTextEdit* editor);
    void save(QPlainTextEdit* editor);
    void saveAs(QPlainTextEdit *editor);
    void exit(QPlainTextEdit* editor);
private:
    QString name_file_;
    QFile *file_;
};

#endif // DOCUMENT_H
