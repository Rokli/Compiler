#include "document.h"

Document::Document(QString name_file){
    file_ = new QFile(name_file);
}

void Document::create(QPlainTextEdit* editor){
    file_->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(file_);
    QString file_content = in.readAll();
    editor->setPlainText(file_content);
    file_->close();
}

void Document::open(QPlainTextEdit* editor){
    QString name_file = QFileDialog::getOpenFileName(new QWidget, "Открыть файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");

    file_ = new QFile(name_file);
    file_->open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(file_);
    QString file_content = in.readAll();
    editor->setPlainText(file_content);

    file_->close();
    name_file_ = name_file;
}

void Document::save(QPlainTextEdit* editor){
    file_->open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(file_);
    out << editor->toPlainText();

    file_->close();
}

void Document::saveAs(QPlainTextEdit* editor){
    QString name_file = QFileDialog::getSaveFileName(new QWidget, "Сохранить файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");
    file_ = new QFile(name_file);

    file_->open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(file_);
    out << editor->toPlainText();

    file_->close();
}

void Document::exit(QPlainTextEdit* editor){
    if(file_->isOpen()){
        file_->close();
    }
    editor->clear();
}
