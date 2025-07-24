/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QLabel *label;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *logo;
    QTextBrowser *result_box;
    QLabel *AgainBox;
    QLabel *AgainBox2;
    QLabel *label_2;
    QWidget *page_6;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *funLabel;
    QLabel *FFLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(931, 588);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QMainWindow{\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.201, fx:0.494, fy:0.505864, stop:0 rgba(98, 98, 98, 255), stop:1 rgba(255, 255, 255, 255))\n"
"}\n"
"QPushButton\n"
"{\n"
"color:white;\n"
"background-color:Black;\n"
"border: 2px solid white;\n"
"border-radius: 10px;\n"
"padding: 10px;\n"
"margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"background-color:white;\n"
"color:red;\n"
"}\n"
"\n"
"\n"
"QTextEdit\n"
"{\n"
"color:white;\n"
"background-color:Black;\n"
"border: 2px solid white;\n"
"padding: 10px;\n"
"margin: 5px;\n"
"}\n"
"\n"
"QcomboBox\n"
"{\n"
"color: black;\n"
"background-color:Black;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        gridLayout = new QGridLayout(page_5);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(page_5);
        pushButton_2->setObjectName("pushButton_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Stencil")});
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(pushButton_2, 7, 1, 1, 1);

        label = new QLabel(page_5);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Showcard Gothic")});
        font1.setPointSize(12);
        font1.setUnderline(true);
        label->setFont(font1);
        label->setFrameShape(QFrame::Shape::Box);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 5);

        textEdit = new QTextEdit(page_5);
        textEdit->setObjectName("textEdit");
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));

        gridLayout->addWidget(textEdit, 6, 1, 1, 5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 3, 1, 1);

        pushButton = new QPushButton(page_5);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(pushButton, 7, 5, 1, 1);

        comboBox = new QComboBox(page_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Terminal")});
        comboBox->setFont(font2);
        comboBox->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));
        comboBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        comboBox->setEditable(false);

        gridLayout->addWidget(comboBox, 1, 1, 1, 5);

        logo = new QLabel(page_5);
        logo->setObjectName("logo");
        logo->setStyleSheet(QString::fromUtf8("   Image\n"
"    {\n"
"        id:underlyingImage\n"
"        width: 400\n"
"        height: 400\n"
"        x:0;\n"
"        y:0;\n"
"        source:\"pngimg.com - crusader_PNG42.png\"\n"
"        z:1\n"
"    }"));

        gridLayout->addWidget(logo, 2, 1, 2, 1);

        result_box = new QTextBrowser(page_5);
        result_box->setObjectName("result_box");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(9);
        result_box->setFont(font3);
        result_box->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ForbiddenCursor)));

        gridLayout->addWidget(result_box, 2, 3, 1, 2);

        AgainBox = new QLabel(page_5);
        AgainBox->setObjectName("AgainBox");

        gridLayout->addWidget(AgainBox, 5, 1, 1, 1);

        AgainBox2 = new QLabel(page_5);
        AgainBox2->setObjectName("AgainBox2");
        AgainBox2->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        gridLayout->addWidget(AgainBox2, 5, 5, 1, 1);

        label_2 = new QLabel(page_5);
        label_2->setObjectName("label_2");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Small Fonts")});
        label_2->setFont(font4);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 4, 1, 1, 4);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        label_3 = new QLabel(page_6);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 150, 551, 121));
        label_3->setBaseSize(QSize(30, 30));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("System")});
        font5.setPointSize(60);
        font5.setBold(true);
        font5.setUnderline(true);
        label_3->setFont(font5);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_3 = new QPushButton(page_6);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(380, 260, 131, 61));
        stackedWidget->addWidget(page_6);

        verticalLayout->addWidget(stackedWidget);

        funLabel = new QLabel(centralwidget);
        funLabel->setObjectName("funLabel");

        verticalLayout->addWidget(funLabel);

        FFLabel = new QLabel(centralwidget);
        FFLabel->setObjectName("FFLabel");

        verticalLayout->addWidget(FFLabel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 931, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "GAG-CCENT GENERATOR", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Send it!", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Choose an accent!", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Medieval", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "French", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Pirate", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Backwards", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Spoiled Victorian Child", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Binary", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Brainrot", nullptr));

        logo->setText(QString());
        AgainBox->setText(QString());
        AgainBox2->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "                                                                           Input your text here!", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "GAG-CCENT GENERATOR!", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Start!", nullptr));
        funLabel->setText(QString());
        FFLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
