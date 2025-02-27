#include "styletheme.h"

StyleTheme::StyleTheme() {
    darkTheme_ = R"(QPushButton {
        background-color: #333;
        color: white;
        border-radius: 8px;
        padding: 5px;
        font-size: 14px;
        }

        QPushButton:hover {
            background-color: #555;
        }

        QPushButton:pressed {
            background-color: #777;
        }

        QTabWidget {
            background-color: #2E2E2E;
            color: #D8D8D8;
            border: 2px solid #555555;
            border-radius: 8px;
        }

        QTabWidget::pane {
            border: none;
            background-color: #2E2E2E;
        }

        QTabBar::tab {
            background-color: #3C3C3C;
            color: #D8D8D8;
            padding: 10px;
            border-radius: 5px;
            min-width: 100px;
        }

        QTabBar::tab:selected {
            background-color: #5C6BC0;
            color: white;
            border-radius: 5px;
        }

        QTabBar::tab:hover {
            background-color: #4C4C4C;
            color: white;
        }

        QTabBar::tab:pressed {
            background-color: #6A7F93;
            color: white;
        }


        QTableWidget {
            background-color: #333333;
            color: #D8D8D8;
            border: 1px solid #555555;
        }

        QHeaderView::section {
            background-color: #444444;
            color: #D8D8D8;
            padding: 5px;
            border: 1px solid #555555;
        }

        QTableWidget::item {
            background-color: #333333;
            color: #D8D8D8;
            border: 1px solid #555555;
        }

        QTableWidget::item:selected {
            background-color: #5C6BC0;
            color: white;
        }

        QTableWidget::horizontalHeader {
            background-color: #444444;
        }

        QTableWidget::verticalHeader {
            background-color: #444444;
        }

        QHeaderView::section {
            background-color: #444444;
            color: #D8D8D8;
            padding: 8px;
            border: 1px solid #555555;
            border-radius: 5px;
        }

        QTableCornerButton::section {
            background-color: #444444;
            border: none;
        }



        QMainWindow {
            background-color: #2E2E2E;
            color: #D8D8D8;
            border: 1px solid #555555;
            border-radius: 8px;
        }

        QMenuBar {
            background-color: #333333;
            color: #D8D8D8;
            border-bottom: 1px solid #555555;
        }

        QMenuBar::item {
            background-color: #333333;
            padding: 10px;
            border-radius: 5px;
        }

        QMenuBar::item:selected {
            background-color: #5C6BC0;
            color: white;
        }


        QLineEdit {
            background-color: #3C3C3C;
            color: #D8D8D8;
            border: 1px solid #555555;
            border-radius: 5px;
            padding: 5px;
        }


        QMessageBox {
            background-color: #333333;
            color: #D8D8D8;
            border-radius: 10px;
            font-family: Arial, sans-serif;
            font-size: 14px;
        }

        QMessageBox QPushButton {
            background-color: #444444;
            color: #D8D8D8;
            border: 1px solid #555555;
            border-radius: 5px; /
            padding: 5px 10px;
        }

        QMessageBox QPushButton:hover {
            background-color: #5C6BC0;
            color: white;
        }

        QMessageBox QPushButton:pressed {
            background-color: #3F51B5;
            color: white;
        }

        QMessageBox QLabel {
            color: #D8D8D8;
        }
    )";

    ligthTheme_ = R"(QPushButton {
            background-color: #F0F0F0;
            color: #333333;
            border-radius: 8px;
            padding: 5px;
            font-size: 14px;
        }

        QPushButton:hover {
            background-color: #DDDDDD;
        }

        QPushButton:pressed {
            background-color: #BBBBBB;
        }

        QTabWidget {
            background-color: #FFFFFF;
            color: #333333;
            border: 2px solid #CCCCCC;
            border-radius: 8px;
        }

        QTabWidget::pane {
            border: none;
            background-color: #FFFFFF;
        }

        QTabBar::tab {
            background-color: #F5F5F5;
            color: #333333;
            padding: 10px;
            border-radius: 5px;
            min-width: 100px;
        }

        QTabBar::tab:selected {
            background-color: #4CAF50;
            color: white;
            border-radius: 5px;
        }

        QTabBar::tab:hover {
            background-color: #E0E0E0;
            color: #333333;
        }

        QTabBar::tab:pressed {
            background-color: #388E3C;
            color: white;
        }


        QTableWidget {
            background-color: #FFFFFF;
            color: #333333;
            border: 1px solid #CCCCCC;
        }

        QHeaderView::section {
            background-color: #F1F1F1;
            color: #333333;
            padding: 5px;
            border: 1px solid #CCCCCC;
        }

        QTableWidget::item {
            background-color: #FFFFFF;
            color: #333333;
            border: 1px solid #CCCCCC;
        }

        QTableWidget::item:selected {
            background-color: #4CAF50;
            color: white;
        }

        QTableWidget::horizontalHeader {
            background-color: #F1F1F1;
        }

        QTableWidget::verticalHeader {
            background-color: #F1F1F1;
        }

        QHeaderView::section {
            background-color: #F1F1F1;
            color: #333333;
            padding: 8px;
            border: 1px solid #CCCCCC;
            border-radius: 5px;
        }

        QTableCornerButton::section {
            background-color: #F1F1F1;
            border: none;
        }



        QMainWindow {
            background-color: #FFFFFF;
            color: #333333;
            border: 1px solid #CCCCCC;
            border-radius: 8px;
        }

        QMenuBar {
            background-color: #F0F0F0;
            color: #333333;
            border-bottom: 1px solid #CCCCCC;
        }

        QMenuBar::item {
            background-color: #F0F0F0;
            padding: 10px;
            border-radius: 5px;
        }

        QMenuBar::item:selected {
            background-color: #4CAF50;
            color: white;
        }


        QLineEdit {
            background-color: #F9F9F9;
            color: #333333;
            border: 1px solid #CCCCCC;
            border-radius: 5px;
            padding: 5px;
        }


        QMessageBox {
            background-color: #FFFFFF;
            color: #333333;
            border-radius: 10px;
            font-family: Arial, sans-serif;
            font-size: 14px;
        }

        QMessageBox QPushButton {
            background-color: #F0F0F0;
            color: #333333;
            border: 1px solid #CCCCCC;
            border-radius: 5px;
            padding: 5px 10px;
        }

        QMessageBox QPushButton:hover {
            background-color: #DDDDDD;
            color: white;
        }

        QMessageBox QPushButton:pressed {
            background-color: #BBBBBB;
            color: white;
        }

        QMessageBox QLabel {
            color: #333333;
        }
    )";
    theme_ = false;
}
