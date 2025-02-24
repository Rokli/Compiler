#include "document.h"

Document::Document(QString name_file){
    file_ = new QFile(name_file);
}

void Document::create(QPlainTextEdit* editor){
    name_file_ = QFileDialog::getSaveFileName(nullptr,
                                                    "Сохранить файл",
                                                    QDir::homePath(),
                                                    "Текстовые файлы (*.txt);;Все файлы (*.*)");

    if (name_file_.isEmpty()) {
        return;
    }

    this->file_ = new QFile(name_file_);

    if (!this->file_->open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr,
                             "Ошибка",
                             "Не удалось создать файл");
        return;
    }

    QTextStream out(this->file_);
    out << editor->toPlainText();
    this->file_->close();
}

void Document::open(QPlainTextEdit* editor){
    name_file_ = QFileDialog::getOpenFileName(new QWidget,
                                                    "Открыть файл",
                                                    "",
                                                    "Текстовые файлы (*.txt);;Все файлы (*)");

    file_ = new QFile(name_file_);
    file_->open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(file_);
    QString file_content = in.readAll();
    editor->setPlainText(file_content);

    file_->close();
}

void Document::open(QString filePath,QPlainTextEdit* editor){\
    name_file_ = filePath;
    file_ = new QFile(filePath);
    file_->open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(file_);
    QString file_content = in.readAll();
    editor->setPlainText(file_content);

    file_->close();
}

void Document::save(QPlainTextEdit* editor){
    file_->open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(file_);
    out << editor->toPlainText();

    file_->close();
}

void Document::saveAs(QPlainTextEdit* editor){
    name_file_ = QFileDialog::getSaveFileName(new QWidget,
                                                     "Сохранить файл",
                                                     "",
                                                     "Текстовые файлы (*.txt);;Все файлы (*)");
    file_ = new QFile(name_file_);

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

QString Document::getFileName(){
    return name_file_;
}
