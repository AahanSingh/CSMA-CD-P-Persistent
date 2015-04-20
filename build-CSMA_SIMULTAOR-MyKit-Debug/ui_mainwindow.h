/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_5;
    QLabel *nodeA;
    QLabel *nodeB;
    QLabel *nodeC;
    QLabel *nodeD;
    QPushButton *pushButton_2;
    QLabel *nodeE;
    QLabel *nodeF;
    QTextEdit *textEdit_10;
    QTextEdit *textEdit_12;
    QTextEdit *textEdit_7;
    QTextEdit *textEdit_18;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_19;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_20;
    QTextEdit *textEdit_15;
    QTextEdit *textEdit_25;
    QTextEdit *textEdit_22;
    QTextEdit *textEdit_23;
    QTextEdit *textEdit_14;
    QTextEdit *textEdit_24;
    QTextEdit *textEdit_21;
    QTextEdit *textEdit_17;
    QTextEdit *textEdit_13;
    QTextEdit *textEdit_9;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_11;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_8;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_16;
    QTextEdit *textEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit_26;
    QLabel *label_3;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QTextEdit *senderData;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QTextEdit *receiverData;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(700, 500));
        MainWindow->setMaximumSize(QSize(800, 500));
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(12, 363, 135, 16));
        label_5->setAlignment(Qt::AlignCenter);
        nodeA = new QLabel(centralWidget);
        nodeA->setObjectName(QStringLiteral("nodeA"));
        nodeA->setGeometry(QRect(30, 310, 16, 16));
        nodeA->setAlignment(Qt::AlignCenter);
        nodeB = new QLabel(centralWidget);
        nodeB->setObjectName(QStringLiteral("nodeB"));
        nodeB->setGeometry(QRect(120, 310, 16, 16));
        nodeB->setAlignment(Qt::AlignCenter);
        nodeC = new QLabel(centralWidget);
        nodeC->setObjectName(QStringLiteral("nodeC"));
        nodeC->setGeometry(QRect(300, 310, 16, 16));
        nodeC->setAlignment(Qt::AlignCenter);
        nodeD = new QLabel(centralWidget);
        nodeD->setObjectName(QStringLiteral("nodeD"));
        nodeD->setGeometry(QRect(450, 310, 16, 16));
        nodeD->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 410, 99, 27));
        nodeE = new QLabel(centralWidget);
        nodeE->setObjectName(QStringLiteral("nodeE"));
        nodeE->setGeometry(QRect(570, 310, 16, 16));
        nodeE->setAlignment(Qt::AlignCenter);
        nodeF = new QLabel(centralWidget);
        nodeF->setObjectName(QStringLiteral("nodeF"));
        nodeF->setGeometry(QRect(750, 310, 16, 16));
        nodeF->setAlignment(Qt::AlignCenter);
        textEdit_10 = new QTextEdit(centralWidget);
        textEdit_10->setObjectName(QStringLiteral("textEdit_10"));
        textEdit_10->setGeometry(QRect(480, 332, 20, 20));
        textEdit_10->setMaximumSize(QSize(20, 20));
        textEdit_10->setReadOnly(true);
        textEdit_12 = new QTextEdit(centralWidget);
        textEdit_12->setObjectName(QStringLiteral("textEdit_12"));
        textEdit_12->setGeometry(QRect(420, 332, 20, 20));
        textEdit_12->setMaximumSize(QSize(20, 20));
        textEdit_12->setReadOnly(true);
        textEdit_7 = new QTextEdit(centralWidget);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setGeometry(QRect(570, 332, 20, 20));
        textEdit_7->setMaximumSize(QSize(20, 20));
        textEdit_7->setReadOnly(true);
        textEdit_18 = new QTextEdit(centralWidget);
        textEdit_18->setObjectName(QStringLiteral("textEdit_18"));
        textEdit_18->setGeometry(QRect(240, 332, 20, 20));
        textEdit_18->setMaximumSize(QSize(20, 20));
        textEdit_18->setReadOnly(true);
        textEdit_5 = new QTextEdit(centralWidget);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(630, 332, 20, 20));
        textEdit_5->setMaximumSize(QSize(20, 20));
        textEdit_5->setReadOnly(true);
        textEdit_19 = new QTextEdit(centralWidget);
        textEdit_19->setObjectName(QStringLiteral("textEdit_19"));
        textEdit_19->setGeometry(QRect(210, 332, 20, 20));
        textEdit_19->setMaximumSize(QSize(20, 20));
        textEdit_19->setReadOnly(true);
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(720, 332, 20, 20));
        textEdit_2->setMaximumSize(QSize(20, 20));
        textEdit_2->setReadOnly(true);
        textEdit_20 = new QTextEdit(centralWidget);
        textEdit_20->setObjectName(QStringLiteral("textEdit_20"));
        textEdit_20->setGeometry(QRect(180, 332, 20, 20));
        textEdit_20->setMaximumSize(QSize(20, 20));
        textEdit_20->setReadOnly(true);
        textEdit_15 = new QTextEdit(centralWidget);
        textEdit_15->setObjectName(QStringLiteral("textEdit_15"));
        textEdit_15->setGeometry(QRect(330, 332, 20, 20));
        textEdit_15->setMaximumSize(QSize(20, 20));
        textEdit_15->setReadOnly(true);
        textEdit_25 = new QTextEdit(centralWidget);
        textEdit_25->setObjectName(QStringLiteral("textEdit_25"));
        textEdit_25->setGeometry(QRect(30, 332, 20, 20));
        textEdit_25->setMaximumSize(QSize(20, 20));
        textEdit_25->setReadOnly(true);
        textEdit_22 = new QTextEdit(centralWidget);
        textEdit_22->setObjectName(QStringLiteral("textEdit_22"));
        textEdit_22->setGeometry(QRect(120, 332, 20, 20));
        textEdit_22->setMaximumSize(QSize(20, 20));
        textEdit_22->setReadOnly(true);
        textEdit_23 = new QTextEdit(centralWidget);
        textEdit_23->setObjectName(QStringLiteral("textEdit_23"));
        textEdit_23->setGeometry(QRect(90, 332, 20, 20));
        textEdit_23->setMaximumSize(QSize(20, 20));
        textEdit_23->setReadOnly(true);
        textEdit_14 = new QTextEdit(centralWidget);
        textEdit_14->setObjectName(QStringLiteral("textEdit_14"));
        textEdit_14->setGeometry(QRect(360, 332, 20, 20));
        textEdit_14->setMaximumSize(QSize(20, 20));
        textEdit_14->setReadOnly(true);
        textEdit_24 = new QTextEdit(centralWidget);
        textEdit_24->setObjectName(QStringLiteral("textEdit_24"));
        textEdit_24->setGeometry(QRect(60, 332, 20, 20));
        textEdit_24->setMaximumSize(QSize(20, 20));
        textEdit_24->setReadOnly(true);
        textEdit_21 = new QTextEdit(centralWidget);
        textEdit_21->setObjectName(QStringLiteral("textEdit_21"));
        textEdit_21->setGeometry(QRect(150, 332, 20, 20));
        textEdit_21->setMaximumSize(QSize(20, 20));
        textEdit_21->setReadOnly(true);
        textEdit_17 = new QTextEdit(centralWidget);
        textEdit_17->setObjectName(QStringLiteral("textEdit_17"));
        textEdit_17->setGeometry(QRect(270, 332, 20, 20));
        textEdit_17->setMaximumSize(QSize(20, 20));
        textEdit_17->setReadOnly(true);
        textEdit_13 = new QTextEdit(centralWidget);
        textEdit_13->setObjectName(QStringLiteral("textEdit_13"));
        textEdit_13->setGeometry(QRect(390, 332, 20, 20));
        textEdit_13->setMaximumSize(QSize(20, 20));
        textEdit_13->setReadOnly(true);
        textEdit_9 = new QTextEdit(centralWidget);
        textEdit_9->setObjectName(QStringLiteral("textEdit_9"));
        textEdit_9->setGeometry(QRect(510, 332, 20, 20));
        textEdit_9->setMaximumSize(QSize(20, 20));
        textEdit_9->setReadOnly(true);
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(660, 332, 20, 20));
        textEdit_4->setMaximumSize(QSize(20, 20));
        textEdit_4->setReadOnly(true);
        textEdit_11 = new QTextEdit(centralWidget);
        textEdit_11->setObjectName(QStringLiteral("textEdit_11"));
        textEdit_11->setGeometry(QRect(450, 332, 20, 20));
        textEdit_11->setMaximumSize(QSize(20, 20));
        textEdit_11->setReadOnly(true);
        textEdit_6 = new QTextEdit(centralWidget);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(600, 332, 20, 20));
        textEdit_6->setMaximumSize(QSize(20, 20));
        textEdit_6->setReadOnly(true);
        textEdit_8 = new QTextEdit(centralWidget);
        textEdit_8->setObjectName(QStringLiteral("textEdit_8"));
        textEdit_8->setGeometry(QRect(540, 332, 20, 20));
        textEdit_8->setMaximumSize(QSize(20, 20));
        textEdit_8->setReadOnly(true);
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(690, 332, 20, 20));
        textEdit_3->setMaximumSize(QSize(20, 20));
        textEdit_3->setReadOnly(true);
        textEdit_16 = new QTextEdit(centralWidget);
        textEdit_16->setObjectName(QStringLiteral("textEdit_16"));
        textEdit_16->setGeometry(QRect(300, 332, 20, 20));
        textEdit_16->setMaximumSize(QSize(20, 20));
        textEdit_16->setReadOnly(true);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(750, 332, 20, 20));
        textEdit->setMaximumSize(QSize(20, 20));
        textEdit->setReadOnly(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 771, 151));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        textEdit_26 = new QTextEdit(widget);
        textEdit_26->setObjectName(QStringLiteral("textEdit_26"));

        verticalLayout_3->addWidget(textEdit_26);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        senderData = new QTextEdit(widget);
        senderData->setObjectName(QStringLiteral("senderData"));

        horizontalLayout_4->addWidget(senderData);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_3->addWidget(label_13);

        receiverData = new QTextEdit(widget);
        receiverData->setObjectName(QStringLiteral("receiverData"));

        horizontalLayout_3->addWidget(receiverData);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_7->addLayout(verticalLayout_6);

        MainWindow->setCentralWidget(centralWidget);
        comboBox->raise();
        comboBox_2->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_5->raise();
        nodeA->raise();
        nodeB->raise();
        nodeC->raise();
        nodeD->raise();
        pushButton_2->raise();
        textEdit_25->raise();
        textEdit_24->raise();
        label_4->raise();
        textEdit_26->raise();
        pushButton->raise();
        label_4->raise();
        nodeE->raise();
        nodeF->raise();
        textEdit_25->raise();
        textEdit_25->raise();
        senderData->raise();
        receiverData->raise();
        pushButton->raise();
        label_12->raise();
        label_13->raise();
        label_5->raise();
        textEdit_10->raise();
        textEdit_12->raise();
        textEdit_7->raise();
        textEdit_18->raise();
        textEdit_5->raise();
        textEdit_19->raise();
        textEdit_2->raise();
        textEdit_20->raise();
        textEdit_15->raise();
        textEdit_25->raise();
        textEdit_22->raise();
        textEdit_23->raise();
        textEdit_14->raise();
        textEdit_24->raise();
        textEdit_21->raise();
        textEdit_17->raise();
        textEdit_13->raise();
        textEdit_9->raise();
        textEdit_4->raise();
        textEdit_11->raise();
        textEdit_6->raise();
        textEdit_8->raise();
        textEdit_3->raise();
        textEdit_16->raise();
        textEdit->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CSMA/CD P PERSISTENT SIMULATOR", 0));
        label_5->setText(QApplication::translate("MainWindow", "TRANSMISSION LINE", 0));
        nodeA->setText(QApplication::translate("MainWindow", "A", 0));
        nodeB->setText(QApplication::translate("MainWindow", "B", 0));
        nodeC->setText(QApplication::translate("MainWindow", "C", 0));
        nodeD->setText(QApplication::translate("MainWindow", "D", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "NEXT STEP", 0));
        nodeE->setText(QApplication::translate("MainWindow", "E", 0));
        nodeF->setText(QApplication::translate("MainWindow", "F", 0));
        label_4->setText(QApplication::translate("MainWindow", "SEND MESSAGE", 0));
        label->setText(QApplication::translate("MainWindow", "sender", 0));
        label_2->setText(QApplication::translate("MainWindow", "reciever", 0));
        label_3->setText(QApplication::translate("MainWindow", "data", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Send", 0));
        label_12->setText(QApplication::translate("MainWindow", "Sender Data", 0));
        label_13->setText(QApplication::translate("MainWindow", "Receiver Data", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
