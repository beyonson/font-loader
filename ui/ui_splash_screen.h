/********************************************************************************
** Form generated from reading UI file 'splash_screencTmUHl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SPLASH_SCREENCTMUHL_H
#define SPLASH_SCREENCTMUHL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SplashScreen
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *container;
    QHBoxLayout *horizontalLayout;
    QFrame *circleBg;
    QVBoxLayout *verticalLayout_2;
    QFrame *texts;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QFrame *fontFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *fontSelected;
    QLabel *title;
    QFrame *percentFrame;
    QLabel *loading;

    void setupUi(QMainWindow *SplashScreen)
    {
        if (SplashScreen->objectName().isEmpty())
            SplashScreen->setObjectName(QString::fromUtf8("SplashScreen"));
        SplashScreen->resize(300, 300);
        SplashScreen->setMinimumSize(QSize(300, 300));
        SplashScreen->setMaximumSize(QSize(300, 300));
        centralwidget = new QWidget(SplashScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        container = new QFrame(centralwidget);
        container->setObjectName(QString::fromUtf8("container"));
        container->setFrameShape(QFrame::NoFrame);
        container->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(container);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 20, 20, 20);
        circleBg = new QFrame(container);
        circleBg->setObjectName(QString::fromUtf8("circleBg"));
        circleBg->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #313244;\n"
"	color:  #cdd6f4;\n"
"	border-radius: 120;\n"
"	font: 9pt \"Segoe Ui\";\n"
"}"));
        circleBg->setFrameShape(QFrame::NoFrame);
        circleBg->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(circleBg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        texts = new QFrame(circleBg);
        texts->setObjectName(QString::fromUtf8("texts"));
        texts->setMaximumSize(QSize(16777215, 180));
        texts->setStyleSheet(QString::fromUtf8("background: none;"));
        texts->setFrameShape(QFrame::StyledPanel);
        texts->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(texts);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fontFrame = new QFrame(texts);
        fontFrame->setObjectName(QString::fromUtf8("fontFrame"));
        fontFrame->setFrameShape(QFrame::NoFrame);
        fontFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(fontFrame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        fontSelected = new QLabel(fontFrame);
        fontSelected->setObjectName(QString::fromUtf8("fontSelected"));
        fontSelected->setMinimumSize(QSize(200, 24));
        fontSelected->setMaximumSize(QSize(200, 24));
        fontSelected->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #a6adc8;\n"
"	border-radius: 12px;\n"
"	background-color: #6c7086;\n"
"}"));
        fontSelected->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(fontSelected, 0, Qt::AlignHCenter);


        gridLayout->addWidget(fontFrame, 2, 0, 1, 1);

        title = new QLabel(texts);
        title->setObjectName(QString::fromUtf8("title"));
        title->setMinimumSize(QSize(0, 30));
        title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(title, 0, 0, 1, 1);

        percentFrame = new QFrame(texts);
        percentFrame->setObjectName(QString::fromUtf8("percentFrame"));
        percentFrame->setMinimumSize(QSize(0, 60));
        percentFrame->setMaximumSize(QSize(16777215, 80));
        percentFrame->setFrameShape(QFrame::StyledPanel);
        percentFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(percentFrame, 1, 0, 1, 1);

        loading = new QLabel(texts);
        loading->setObjectName(QString::fromUtf8("loading"));
        loading->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(loading, 3, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_2->addWidget(texts);


        horizontalLayout->addWidget(circleBg);


        verticalLayout->addWidget(container);

        SplashScreen->setCentralWidget(centralwidget);

        retranslateUi(SplashScreen);

        QMetaObject::connectSlotsByName(SplashScreen);
    } // setupUi

    void retranslateUi(QMainWindow *SplashScreen)
    {
        SplashScreen->setWindowTitle(QCoreApplication::translate("SplashScreen", "Loading", nullptr));
        fontSelected->setText(QCoreApplication::translate("SplashScreen", "Font Selected:", nullptr));
        title->setText(QCoreApplication::translate("SplashScreen", "Whiteboard Typerwriter", nullptr));
        loading->setText(QCoreApplication::translate("SplashScreen", "loading...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SplashScreen: public Ui_SplashScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SPLASH_SCREENCTMUHL_H
