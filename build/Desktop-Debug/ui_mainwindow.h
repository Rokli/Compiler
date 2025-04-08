/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *create;
    QAction *open;
    QAction *save;
    QAction *saveAs;
    QAction *exit;
    QAction *ovveride;
    QAction *replace;
    QAction *cut;
    QAction *copy;
    QAction *insert;
    QAction *remove;
    QAction *select_all;
    QAction *statmentProblem;
    QAction *grammar;
    QAction *classificationGrammar;
    QAction *analysisMethod;
    QAction *diagnosticsAnalysisError;
    QAction *testCase;
    QAction *references;
    QAction *sourceCodeProgramm;
    QAction *callReference;
    QAction *aboutReference;
    QAction *customizeFont;
    QAction *changeLang;
    QAction *changeTheme;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QPushButton *createDocumentButton;
    QPushButton *openDocumentButton;
    QPushButton *saveDocumentButton;
    QPushButton *ovverideButton;
    QPushButton *replaceButton;
    QPushButton *copyButton;
    QPushButton *cutButton;
    QPushButton *insertButton;
    QTabWidget *tabWidget;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEditor;
    QMenu *menuText;
    QMenu *command;
    QMenu *reference;
    QMenu *settings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #333;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #555;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #777;\n"
"}\n"
"\n"
"QTabWidget {\n"
"    background-color: #2E2E2E;  /* \320\221\320\276\320\273\320\265\320\265 \320\274\321\217\320\263\320\272\320\270\320\271 \321\202\321\221\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 */\n"
"    color: #D8D8D8;  /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #555555;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: none;\n"
"    background-color: #2E2E2E;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #3C3C3C;  /* \320\235\320\265\320\274\320\275\320\276\320\263\320\276 \321\201\320\262\320\265\321\202\320\273\320\265\320\265 */\n"
"    color: #D8D8D8;  /* \320\241"
                        "\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    padding: 10px;\n"
"    border-radius: 5px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #5C6BC0;  /* \320\233\320\265\320\263\320\272\320\270\320\271 \321\201\320\270\320\275\320\270\320\271 \320\276\321\202\321\202\320\265\320\275\320\276\320\272 \320\264\320\273\321\217 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\260\320\261\320\260 */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #4C4C4C;  /* \320\235\320\265\320\274\320\275\320\276\320\263\320\276 \321\201\320\262\320\265\321\202\320\273\320\265\320\265 \320\275\320\260 \321\205\320\276\320\262\320\265\321\200 */\n"
"    color: white;\n"
"}\n"
"\n"
"QTabBar::tab:pressed {\n"
"    background-color: #6A7F93;  /* \320\221\320\276\320\273\320\265\320\265 \321\205\320\276\320\273\320\276\320\264"
                        "\320\275\321\213\320\271 \320\276\321\202\321\202\320\265\320\275\320\276\320\272 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    color: white;\n"
"}\n"
"\n"
"\n"
"QTableWidget {\n"
"    background-color: #333333; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\201\320\265\320\263\320\276 table */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 1px solid #555555;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #444444; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262 */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320"
                        "\262 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260\321\205 */\n"
"    padding: 5px;\n"
"    border: 1px solid #555555; /* \320\240\320\260\320\274\320\272\320\260 \320\264\320\273\321\217 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    background-color: #333333; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\217\321\207\320\265\320\265\320\272 */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\262 \321\217\321\207\320\265\320\271\320\272\320\260\321\205 */\n"
"    border: 1px solid #555555; /* \320\240\320\260\320\274\320\272\320\260 \320\264\320\273\321\217 \321\217\321\207\320\265\320\265\320\272 */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #5C6BC0; /* \320\241\320\270\320\275\320\270\320\271 \321\204\320\276\320\275 \320\264\320\273\321"
                        "\217 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\321\205 \321\217\321\207\320\265\320\265\320\272 */\n"
"    color: white;\n"
"}\n"
"\n"
"QTableWidget::horizontalHeader {\n"
"    background-color: #444444; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\261\320\265\320\273\321\213\320\271 \321\204\320\276\320\275 \321\203 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\321\205 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"}\n"
"\n"
"QTableWidget::verticalHeader {\n"
"    background-color: #444444; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\261\320\265\320\273\321\213\320\271 \321\204\320\276\320\275 \321\203 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\321\205 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-colo"
                        "r: #444444; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"    padding: 8px;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #444444;\n"
"    border: none;\n"
"}\n"
"\n"
"\n"
"\n"
"QMainWindow {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\276\320\272\320\275\320\260 */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 1px solid #555555;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #"
                        "333333; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\274\320\265\320\275\321\216 */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\262 \320\274\320\265\320\275\321\216 */\n"
"    border-bottom: 1px solid #555555;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background-color: #333333;\n"
"    padding: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #5C6BC0; /* \320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\270\320\265 \320\277\321\203\320\275\320\272\321\202\320\276\320\262 \320\274\320\265\320\275\321\216 */\n"
"    color: white;\n"
"}\n"
"\n"
"\n"
"QLineEdit {\n"
"    background-color: #3C3C3C; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\277\320\276\320\273\320\265\320\271 \320\262\320\262\320\276\320\264\320\260 */\n"
"    color: #D8D8D8; /* \320"
                        "\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 1px solid #555555;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"\n"
"QMessageBox {\n"
"    background-color: #333333; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\201\320\265\320\263\320\276 \320\276\320\272\320\275\320\260 */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border-radius: 10px; /* \320\236\320\272\321\200\321\203\320\263\320\273\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    font-family: Arial, sans-serif; /* \320\250\321\200\320\270\321\204\321\202 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QMessageBox QPushButton {\n"
"    background-color: #444444; /* \320\242\320\265\320\274\320\275\321\213"
                        "\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\260\321\205 */\n"
"    border: 1px solid #555555; /* \320\240\320\260\320\274\320\272\320\260 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"    border-radius: 5px; /* \320\236\320\272\321\200\321\203\320\263\320\273\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"    padding: 5px 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262 \320\272\320\275\320\276\320\277\320\272\320\260\321\205 */\n"
"}\n"
"\n"
"QMessageBox QPushButton:hover {\n"
"    background-color: #5C6BC0; /* \320\246\320\262\320\265\321\202 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\270 \320\275\320\260\320\262\320"
                        "\265\320\264\320\265\320\275\320\270\320\270 */\n"
"    color: white;\n"
"}\n"
"\n"
"QMessageBox QPushButton:pressed {\n"
"    background-color: #3F51B5; /* \320\246\320\262\320\265\321\202 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    color: white;\n"
"}\n"
"\n"
"QMessageBox QLabel {\n"
"    color: #D8D8D8; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\262 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
""));
        create = new QAction(MainWindow);
        create->setObjectName("create");
        open = new QAction(MainWindow);
        open->setObjectName("open");
        save = new QAction(MainWindow);
        save->setObjectName("save");
        saveAs = new QAction(MainWindow);
        saveAs->setObjectName("saveAs");
        exit = new QAction(MainWindow);
        exit->setObjectName("exit");
        ovveride = new QAction(MainWindow);
        ovveride->setObjectName("ovveride");
        replace = new QAction(MainWindow);
        replace->setObjectName("replace");
        cut = new QAction(MainWindow);
        cut->setObjectName("cut");
        copy = new QAction(MainWindow);
        copy->setObjectName("copy");
        insert = new QAction(MainWindow);
        insert->setObjectName("insert");
        remove = new QAction(MainWindow);
        remove->setObjectName("remove");
        select_all = new QAction(MainWindow);
        select_all->setObjectName("select_all");
        statmentProblem = new QAction(MainWindow);
        statmentProblem->setObjectName("statmentProblem");
        grammar = new QAction(MainWindow);
        grammar->setObjectName("grammar");
        classificationGrammar = new QAction(MainWindow);
        classificationGrammar->setObjectName("classificationGrammar");
        analysisMethod = new QAction(MainWindow);
        analysisMethod->setObjectName("analysisMethod");
        diagnosticsAnalysisError = new QAction(MainWindow);
        diagnosticsAnalysisError->setObjectName("diagnosticsAnalysisError");
        testCase = new QAction(MainWindow);
        testCase->setObjectName("testCase");
        references = new QAction(MainWindow);
        references->setObjectName("references");
        sourceCodeProgramm = new QAction(MainWindow);
        sourceCodeProgramm->setObjectName("sourceCodeProgramm");
        callReference = new QAction(MainWindow);
        callReference->setObjectName("callReference");
        aboutReference = new QAction(MainWindow);
        aboutReference->setObjectName("aboutReference");
        customizeFont = new QAction(MainWindow);
        customizeFont->setObjectName("customizeFont");
        changeLang = new QAction(MainWindow);
        changeLang->setObjectName("changeLang");
        changeTheme = new QAction(MainWindow);
        changeTheme->setObjectName("changeTheme");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setMinimumSize(QSize(50, 30));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        createDocumentButton = new QPushButton(splitter);
        createDocumentButton->setObjectName("createDocumentButton");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        createDocumentButton->setIcon(icon);
        splitter->addWidget(createDocumentButton);
        openDocumentButton = new QPushButton(splitter);
        openDocumentButton->setObjectName("openDocumentButton");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        openDocumentButton->setIcon(icon1);
        splitter->addWidget(openDocumentButton);
        saveDocumentButton = new QPushButton(splitter);
        saveDocumentButton->setObjectName("saveDocumentButton");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        saveDocumentButton->setIcon(icon2);
        splitter->addWidget(saveDocumentButton);
        ovverideButton = new QPushButton(splitter);
        ovverideButton->setObjectName("ovverideButton");
        ovverideButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        ovverideButton->setIcon(icon3);
        splitter->addWidget(ovverideButton);
        replaceButton = new QPushButton(splitter);
        replaceButton->setObjectName("replaceButton");
        replaceButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditRedo));
        replaceButton->setIcon(icon4);
        splitter->addWidget(replaceButton);
        copyButton = new QPushButton(splitter);
        copyButton->setObjectName("copyButton");
        copyButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        copyButton->setIcon(icon5);
        splitter->addWidget(copyButton);
        cutButton = new QPushButton(splitter);
        cutButton->setObjectName("cutButton");
        cutButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        cutButton->setIcon(icon6);
        splitter->addWidget(cutButton);
        insertButton = new QPushButton(splitter);
        insertButton->setObjectName("insertButton");
        insertButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        insertButton->setIcon(icon7);
        splitter->addWidget(insertButton);

        verticalLayout->addWidget(splitter);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");

        verticalLayout->addWidget(tabWidget);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 38));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEditor = new QMenu(menubar);
        menuEditor->setObjectName("menuEditor");
        menuText = new QMenu(menubar);
        menuText->setObjectName("menuText");
        command = new QMenu(menubar);
        command->setObjectName("command");
        reference = new QMenu(menubar);
        reference->setObjectName("reference");
        settings = new QMenu(menubar);
        settings->setObjectName("settings");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEditor->menuAction());
        menubar->addAction(menuText->menuAction());
        menubar->addAction(command->menuAction());
        menubar->addAction(settings->menuAction());
        menubar->addAction(reference->menuAction());
        menuFile->addAction(create);
        menuFile->addAction(open);
        menuFile->addAction(save);
        menuFile->addAction(saveAs);
        menuFile->addAction(exit);
        menuEditor->addAction(ovveride);
        menuEditor->addAction(replace);
        menuEditor->addAction(cut);
        menuEditor->addAction(copy);
        menuEditor->addAction(insert);
        menuEditor->addAction(remove);
        menuEditor->addAction(select_all);
        menuText->addAction(statmentProblem);
        menuText->addAction(grammar);
        menuText->addAction(classificationGrammar);
        menuText->addAction(analysisMethod);
        menuText->addAction(diagnosticsAnalysisError);
        menuText->addAction(testCase);
        menuText->addAction(references);
        menuText->addAction(sourceCodeProgramm);
        reference->addAction(callReference);
        reference->addAction(aboutReference);
        settings->addAction(customizeFont);
        settings->addAction(changeLang);
        settings->addAction(changeTheme);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\270\320\273\321\217\321\202\320\276\321\200", nullptr));
        create->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        open->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        saveAs->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        ovveride->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        replace->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214", nullptr));
        cut->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\200\320\265\320\267\320\260\321\202\321\214", nullptr));
        copy->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        insert->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        select_all->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        statmentProblem->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        grammar->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\320\260", nullptr));
        classificationGrammar->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\260\321\201\321\201\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217 \320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\320\270", nullptr));
        analysisMethod->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\260\320\275\320\260\320\273\320\270\320\267\320\260", nullptr));
        diagnosticsAnalysisError->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\320\260\320\263\320\275\320\276\321\201\321\202\320\270\320\272\320\260 \320\270 \320\275\320\265\320\271\321\202\321\200\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\276\321\210\320\270\320\261\320\276\320\272", nullptr));
        testCase->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\321\213\320\271 \320\277\321\200\320\270\320\274\320\265\321\200", nullptr));
        references->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\273\320\270\321\202\320\265\321\200\320\260\321\202\321\203\321\200\321\213", nullptr));
        sourceCodeProgramm->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \320\272\320\276\320\264 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        callReference->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\267\320\276\320\262 \321\201\320\277\321\200\320\260\320\262\320\272\320\270", nullptr));
        aboutReference->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        customizeFont->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\210\321\200\320\270\321\204\321\202", nullptr));
        changeLang->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\217\320\267\321\213\320\272", nullptr));
        changeTheme->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        splitter->setStyleSheet(QString());
        createDocumentButton->setStyleSheet(QString());
        createDocumentButton->setText(QString());
        openDocumentButton->setStyleSheet(QString());
        openDocumentButton->setText(QString());
        saveDocumentButton->setStyleSheet(QString());
        saveDocumentButton->setText(QString());
        ovverideButton->setText(QString());
        replaceButton->setText(QString());
        copyButton->setText(QString());
        cutButton->setText(QString());
        insertButton->setText(QString());
        tabWidget->setStyleSheet(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        tableWidget->setStyleSheet(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menuEditor->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
        menuText->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        command->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\201\320\272", nullptr));
        reference->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        settings->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
