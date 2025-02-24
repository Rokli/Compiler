#include "linenumberarea.h"
#include "codeeditor.h"
#include <QPainter>

LineNumberArea::LineNumberArea(CodeEditor *editor)
    : QWidget(editor), textEditor(editor) {}

QSize LineNumberArea::sizeHint() const {
    return QSize(textEditor->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    textEditor->lineNumberAreaPaintEvent(event);
}
