QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 qscintilla2
LIBS += -L/usr/lib64 -lqscintilla2_qt6
INCLUDEPATH += /usr/include/qt6/Qsci

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Models/codeeditor.cpp \
    Models/document.cpp \
    Models/editing.cpp \
    Models/lexerphp.cpp \
    Models/linenumberarea.cpp \
    Models/programm.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp

HEADERS += \
    Models/codeeditor.h \
    Models/document.h \
    Models/editing.h \
    Models/lexerphp.h \
    Models/linenumberarea.h \
    Models/programm.h \
    mainwindow.h \
    settings.h

FORMS += \
    mainwindow.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

TRANSLATIONS += \
    translate/compiler_en_GB.ts \
    translate/compiler_ru_RU.ts
