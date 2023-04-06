/********************************************************************************
** Form generated from reading UI file 'new-newZvNhOm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NEW_2D_NEWZVNHOM_H
#define NEW_2D_NEWZVNHOM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TypeWriter
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *mainFrame;
    QHBoxLayout *horizontalLayout;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *buttonFrame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *closeButton;
    QPushButton *minButton;
    QPushButton *maxButton;
    QSpacerItem *horizontalSpacer;
    QFrame *fontFileFrame;
    QVBoxLayout *verticalLayout_3;
    QFrame *loadFontFrame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *loadFontLabel;
    QFrame *openFontFrame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *fontLabelFrame;
    QHBoxLayout *horizontalLayout_5;
    QLabel *fontLabel;
    QFrame *fontButtonFrame;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *fontButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QFrame *rightFrame;
    QHBoxLayout *horizontalLayout_7;
    QPlainTextEdit *textInput;

    void setupUi(QMainWindow *TypeWriter)
    {
        if (TypeWriter->objectName().isEmpty())
            TypeWriter->setObjectName(QString::fromUtf8("TypeWriter"));
        TypeWriter->resize(800, 600);
        TypeWriter->setMaximumSize(QSize(16777215, 600));
        TypeWriter->setStyleSheet(QString::fromUtf8("*{\n"
"	border: none;\n"
"	background-color: transparent;\n"
"	background: none;\n"
"	padding: 0;\n"
"	margin: 0;\n"
"}\n"
"\n"
"#mainFrame {\n"
"	background-color: #1b1929;\n"
"	border-radius: 28;\n"
"}\n"
"\n"
"#textInput {\n"
"	background-color: transparent;\n"
"	color: #a6adc8;\n"
"}\n"
"\n"
"#leftFrame {\n"
"	background-color: #1e1e2e;\n"
"	border-top-left-radius: 22;\n"
"	border-bottom-left-radius: 22;\n"
"}\n"
"\n"
"#rightFrame {\n"
"	background-color: #303045;\n"
"	border-top-right-radius: 22;\n"
"	border-bottom-right-radius: 22;\n"
"}\n"
"\n"
"#fontLabel {\n"
"	background-color: #585b70;\n"
"	color: #7f849c;\n"
"	border-radius: 6;\n"
"}\n"
"\n"
"#loadFontLabel {\n"
"	color: #585b70;\n"
"}\n"
"\n"
"#closeButton {\n"
"	background-color: #f38ba8;\n"
"	border-style: solid;\n"
"	border-radius:6px;\n"
"	max-width:12px;\n"
"	max-height:12px;\n"
"	min-width:12px;\n"
"	min-height:12px;\n"
"}\n"
"#minButton {\n"
"	background-color: #f9e2af;\n"
"	border-style: solid;\n"
"	border-radius:6px;\n"
"	max-width:12px;\n"
""
                        "	max-height:12px;\n"
"	min-width:12px;\n"
"	min-height:12px;\n"
"}\n"
"#maxButton {\n"
"	background-color: #a6e3a1;\n"
"	border-style: solid;\n"
"	border-radius:6px;\n"
"	max-width:12px;\n"
"	max-height:12px;\n"
"	min-width:12px;\n"
"	min-height:12px;\n"
"}"));
        centralwidget = new QWidget(TypeWriter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainFrame = new QFrame(centralwidget);
        mainFrame->setObjectName(QString::fromUtf8("mainFrame"));
        mainFrame->setFrameShape(QFrame::StyledPanel);
        mainFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(mainFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftFrame = new QFrame(mainFrame);
        leftFrame->setObjectName(QString::fromUtf8("leftFrame"));
        leftFrame->setMinimumSize(QSize(280, 0));
        leftFrame->setMaximumSize(QSize(280, 16777215));
        leftFrame->setFrameShape(QFrame::NoFrame);
        leftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(leftFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonFrame = new QFrame(leftFrame);
        buttonFrame->setObjectName(QString::fromUtf8("buttonFrame"));
        buttonFrame->setFrameShape(QFrame::StyledPanel);
        buttonFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(buttonFrame);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        closeButton = new QPushButton(buttonFrame);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_2->addWidget(closeButton);

        minButton = new QPushButton(buttonFrame);
        minButton->setObjectName(QString::fromUtf8("minButton"));

        horizontalLayout_2->addWidget(minButton);

        maxButton = new QPushButton(buttonFrame);
        maxButton->setObjectName(QString::fromUtf8("maxButton"));

        horizontalLayout_2->addWidget(maxButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(buttonFrame, 0, Qt::AlignTop);

        fontFileFrame = new QFrame(leftFrame);
        fontFileFrame->setObjectName(QString::fromUtf8("fontFileFrame"));
        fontFileFrame->setMinimumSize(QSize(0, 70));
        fontFileFrame->setMaximumSize(QSize(16777215, 70));
        fontFileFrame->setFrameShape(QFrame::NoFrame);
        fontFileFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(fontFileFrame);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        loadFontFrame = new QFrame(fontFileFrame);
        loadFontFrame->setObjectName(QString::fromUtf8("loadFontFrame"));
        loadFontFrame->setFrameShape(QFrame::NoFrame);
        loadFontFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(loadFontFrame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        loadFontLabel = new QLabel(loadFontFrame);
        loadFontLabel->setObjectName(QString::fromUtf8("loadFontLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Source Code Pro"));
        font.setPointSize(14);
        loadFontLabel->setFont(font);
        loadFontLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(loadFontLabel);


        verticalLayout_3->addWidget(loadFontFrame);

        openFontFrame = new QFrame(fontFileFrame);
        openFontFrame->setObjectName(QString::fromUtf8("openFontFrame"));
        openFontFrame->setFrameShape(QFrame::NoFrame);
        openFontFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(openFontFrame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        fontLabelFrame = new QFrame(openFontFrame);
        fontLabelFrame->setObjectName(QString::fromUtf8("fontLabelFrame"));
        fontLabelFrame->setFrameShape(QFrame::StyledPanel);
        fontLabelFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(fontLabelFrame);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        fontLabel = new QLabel(fontLabelFrame);
        fontLabel->setObjectName(QString::fromUtf8("fontLabel"));
        fontLabel->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(fontLabel);


        horizontalLayout_4->addWidget(fontLabelFrame);

        fontButtonFrame = new QFrame(openFontFrame);
        fontButtonFrame->setObjectName(QString::fromUtf8("fontButtonFrame"));
        fontButtonFrame->setFrameShape(QFrame::StyledPanel);
        fontButtonFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(fontButtonFrame);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_4->addWidget(fontButtonFrame);

        fontButton = new QPushButton(openFontFrame);
        fontButton->setObjectName(QString::fromUtf8("fontButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/greyupload.png"), QSize(), QIcon::Normal, QIcon::Off);
        fontButton->setIcon(icon);
        fontButton->setIconSize(QSize(24, 24));

        horizontalLayout_4->addWidget(fontButton);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(openFontFrame);


        verticalLayout_2->addWidget(fontFileFrame);

        frame_2 = new QFrame(leftFrame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame_2);

        verticalSpacer = new QSpacerItem(20, 380, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        frame = new QFrame(leftFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame);


        horizontalLayout->addWidget(leftFrame);

        rightFrame = new QFrame(mainFrame);
        rightFrame->setObjectName(QString::fromUtf8("rightFrame"));
        rightFrame->setFrameShape(QFrame::NoFrame);
        rightFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(rightFrame);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(30, 50, 30, 30);
        textInput = new QPlainTextEdit(rightFrame);
        textInput->setObjectName(QString::fromUtf8("textInput"));
        QFont font1;
        font1.setPointSize(48);
        textInput->setFont(font1);

        horizontalLayout_7->addWidget(textInput);


        horizontalLayout->addWidget(rightFrame);


        verticalLayout->addWidget(mainFrame);

        TypeWriter->setCentralWidget(centralwidget);

        retranslateUi(TypeWriter);

        QMetaObject::connectSlotsByName(TypeWriter);
    } // setupUi

    void retranslateUi(QMainWindow *TypeWriter)
    {
        TypeWriter->setWindowTitle(QCoreApplication::translate("TypeWriter", "MainWindow", nullptr));
        closeButton->setText(QString());
        minButton->setText(QString());
        maxButton->setText(QString());
        loadFontLabel->setText(QCoreApplication::translate("TypeWriter", "Load Font", nullptr));
        fontLabel->setText(QCoreApplication::translate("TypeWriter", "  C:/font/font.ttf", nullptr));
        fontButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TypeWriter: public Ui_TypeWriter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NEW_2D_NEWZVNHOM_H
