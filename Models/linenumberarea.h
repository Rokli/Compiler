#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H
#include <QApplication>
#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>


class CodeEditor;

class LineNumberArea : public QWidget {
public:
    explicit LineNumberArea(CodeEditor *editor);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    CodeEditor *textEditor;
};

#endif // LINENUMBERAREA_H
