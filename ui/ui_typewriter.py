# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'typewriterVPBaaM.ui'
##
## Created by: Qt User Interface Compiler version 5.15.8
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *  # type: ignore
from PySide2.QtGui import *  # type: ignore
from PySide2.QtWidgets import *  # type: ignore

import resources_rc

class Ui_TypeWriter(object):
    def setupUi(self, TypeWriter):
        if not TypeWriter.objectName():
            TypeWriter.setObjectName(u"TypeWriter")
        TypeWriter.resize(800, 600)
        TypeWriter.setMinimumSize(QSize(800, 600))
        TypeWriter.setMaximumSize(QSize(800, 600))
        TypeWriter.setStyleSheet(u"*{\n"
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
"#fontDirLabel {\n"
"	color: #585b70;\n"
"}\n"
"\n"
"#fontDirList {\n"
"	background-color: transparent;\n"
"	color: #585b70;\n"
"	font-size: 12;\n"
"}\n"
"\n"
"#closeButton {\n"
"	background-color: #f38ba8;\n"
"	border-style: solid;\n"
"	border-radius:6px;\n"
"	max-width:12px;\n"
"	max-height:12px;\n"
"	min-w"
                        "idth:12px;\n"
"	min-height:12px;\n"
"}\n"
"#minButton {\n"
"	background-color: #f9e2af;\n"
"	border-style: solid;\n"
"	border-radius:6px;\n"
"	max-width:12px;\n"
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
"}")
        self.centralwidget = QWidget(TypeWriter)
        self.centralwidget.setObjectName(u"centralwidget")
        self.centralwidget.setMinimumSize(QSize(800, 600))
        self.verticalLayout = QVBoxLayout(self.centralwidget)
        self.verticalLayout.setSpacing(0)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.mainFrame = QFrame(self.centralwidget)
        self.mainFrame.setObjectName(u"mainFrame")
        self.mainFrame.setFrameShape(QFrame.StyledPanel)
        self.mainFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout = QHBoxLayout(self.mainFrame)
        self.horizontalLayout.setSpacing(0)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.leftFrame = QFrame(self.mainFrame)
        self.leftFrame.setObjectName(u"leftFrame")
        self.leftFrame.setMinimumSize(QSize(280, 0))
        self.leftFrame.setMaximumSize(QSize(280, 16777215))
        self.leftFrame.setFrameShape(QFrame.NoFrame)
        self.leftFrame.setFrameShadow(QFrame.Raised)
        self.verticalLayout_2 = QVBoxLayout(self.leftFrame)
        self.verticalLayout_2.setSpacing(6)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.buttonFrame = QFrame(self.leftFrame)
        self.buttonFrame.setObjectName(u"buttonFrame")
        self.buttonFrame.setFrameShape(QFrame.StyledPanel)
        self.buttonFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_2 = QHBoxLayout(self.buttonFrame)
        self.horizontalLayout_2.setSpacing(5)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalLayout_2.setContentsMargins(5, 5, 5, 5)
        self.closeButton = QPushButton(self.buttonFrame)
        self.closeButton.setObjectName(u"closeButton")
        self.closeButton.setCursor(QCursor(Qt.OpenHandCursor))
        self.closeButton.setMouseTracking(True)

        self.horizontalLayout_2.addWidget(self.closeButton)

        self.minButton = QPushButton(self.buttonFrame)
        self.minButton.setObjectName(u"minButton")
        self.minButton.setCursor(QCursor(Qt.OpenHandCursor))
        self.minButton.setMouseTracking(True)

        self.horizontalLayout_2.addWidget(self.minButton)

        self.maxButton = QPushButton(self.buttonFrame)
        self.maxButton.setObjectName(u"maxButton")
        self.maxButton.setCursor(QCursor(Qt.OpenHandCursor))
        self.maxButton.setMouseTracking(True)

        self.horizontalLayout_2.addWidget(self.maxButton)

        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout_2.addItem(self.horizontalSpacer)


        self.verticalLayout_2.addWidget(self.buttonFrame)

        self.fontFileFrame = QFrame(self.leftFrame)
        self.fontFileFrame.setObjectName(u"fontFileFrame")
        self.fontFileFrame.setMinimumSize(QSize(0, 70))
        self.fontFileFrame.setMaximumSize(QSize(16777215, 70))
        self.fontFileFrame.setFrameShape(QFrame.NoFrame)
        self.fontFileFrame.setFrameShadow(QFrame.Raised)
        self.verticalLayout_3 = QVBoxLayout(self.fontFileFrame)
        self.verticalLayout_3.setSpacing(5)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.verticalLayout_3.setContentsMargins(5, 5, 0, 5)
        self.loadFontFrame = QFrame(self.fontFileFrame)
        self.loadFontFrame.setObjectName(u"loadFontFrame")
        self.loadFontFrame.setFrameShape(QFrame.NoFrame)
        self.loadFontFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_3 = QHBoxLayout(self.loadFontFrame)
        self.horizontalLayout_3.setSpacing(0)
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.horizontalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.loadFontLabel = QLabel(self.loadFontFrame)
        self.loadFontLabel.setObjectName(u"loadFontLabel")
        font = QFont()
        font.setFamily(u"Source Code Pro")
        font.setPointSize(14)
        self.loadFontLabel.setFont(font)
        self.loadFontLabel.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignVCenter)

        self.horizontalLayout_3.addWidget(self.loadFontLabel)

        self.fontButton = QPushButton(self.loadFontFrame)
        self.fontButton.setObjectName(u"fontButton")
        self.fontButton.setCursor(QCursor(Qt.OpenHandCursor))
        icon = QIcon()
        icon.addFile(u":/icons/icons/greyupload.png", QSize(), QIcon.Normal, QIcon.Off)
        self.fontButton.setIcon(icon)
        self.fontButton.setIconSize(QSize(24, 24))

        self.horizontalLayout_3.addWidget(self.fontButton, 0, Qt.AlignRight)

        self.horizontalSpacer_2 = QSpacerItem(80, 20, QSizePolicy.Fixed, QSizePolicy.Minimum)

        self.horizontalLayout_3.addItem(self.horizontalSpacer_2)


        self.verticalLayout_3.addWidget(self.loadFontFrame)

        self.openFontFrame = QFrame(self.fontFileFrame)
        self.openFontFrame.setObjectName(u"openFontFrame")
        self.openFontFrame.setFrameShape(QFrame.NoFrame)
        self.openFontFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_4 = QHBoxLayout(self.openFontFrame)
        self.horizontalLayout_4.setSpacing(0)
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.horizontalLayout_4.setContentsMargins(0, 0, 0, 0)
        self.fontLabelFrame = QFrame(self.openFontFrame)
        self.fontLabelFrame.setObjectName(u"fontLabelFrame")
        self.fontLabelFrame.setFrameShape(QFrame.StyledPanel)
        self.fontLabelFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_5 = QHBoxLayout(self.fontLabelFrame)
        self.horizontalLayout_5.setSpacing(0)
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.horizontalLayout_5.setContentsMargins(0, 0, 0, 0)
        self.fontLabel = QLabel(self.fontLabelFrame)
        self.fontLabel.setObjectName(u"fontLabel")
        self.fontLabel.setMinimumSize(QSize(150, 0))

        self.horizontalLayout_5.addWidget(self.fontLabel)


        self.horizontalLayout_4.addWidget(self.fontLabelFrame)

        self.fontButtonFrame = QFrame(self.openFontFrame)
        self.fontButtonFrame.setObjectName(u"fontButtonFrame")
        self.fontButtonFrame.setFrameShape(QFrame.StyledPanel)
        self.fontButtonFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_6 = QHBoxLayout(self.fontButtonFrame)
        self.horizontalLayout_6.setSpacing(0)
        self.horizontalLayout_6.setObjectName(u"horizontalLayout_6")
        self.horizontalLayout_6.setContentsMargins(0, 0, 0, 0)

        self.horizontalLayout_4.addWidget(self.fontButtonFrame)


        self.verticalLayout_3.addWidget(self.openFontFrame)


        self.verticalLayout_2.addWidget(self.fontFileFrame)

        self.verticalSpacer_2 = QSpacerItem(20, 10, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.verticalLayout_2.addItem(self.verticalSpacer_2)

        self.fontDirLabelFrame = QFrame(self.leftFrame)
        self.fontDirLabelFrame.setObjectName(u"fontDirLabelFrame")
        self.fontDirLabelFrame.setFrameShape(QFrame.NoFrame)
        self.fontDirLabelFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_9 = QHBoxLayout(self.fontDirLabelFrame)
        self.horizontalLayout_9.setSpacing(0)
        self.horizontalLayout_9.setObjectName(u"horizontalLayout_9")
        self.horizontalLayout_9.setContentsMargins(5, 0, 0, 0)
        self.fontDirLabel = QLabel(self.fontDirLabelFrame)
        self.fontDirLabel.setObjectName(u"fontDirLabel")
        self.fontDirLabel.setFont(font)

        self.horizontalLayout_9.addWidget(self.fontDirLabel)

        self.fontDirButtonFrame = QFrame(self.fontDirLabelFrame)
        self.fontDirButtonFrame.setObjectName(u"fontDirButtonFrame")
        self.fontDirButtonFrame.setFrameShape(QFrame.StyledPanel)
        self.fontDirButtonFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_10 = QHBoxLayout(self.fontDirButtonFrame)
        self.horizontalLayout_10.setSpacing(0)
        self.horizontalLayout_10.setObjectName(u"horizontalLayout_10")
        self.horizontalLayout_10.setContentsMargins(0, 0, 0, 0)
        self.fontDirButton = QPushButton(self.fontDirButtonFrame)
        self.fontDirButton.setObjectName(u"fontDirButton")
        self.fontDirButton.setCursor(QCursor(Qt.OpenHandCursor))
        icon1 = QIcon()
        icon1.addFile(u":/icons/icons/greyfolder.png", QSize(), QIcon.Normal, QIcon.Off)
        self.fontDirButton.setIcon(icon1)
        self.fontDirButton.setIconSize(QSize(24, 24))

        self.horizontalLayout_10.addWidget(self.fontDirButton, 0, Qt.AlignRight)


        self.horizontalLayout_9.addWidget(self.fontDirButtonFrame)

        self.horizontalSpacer_3 = QSpacerItem(80, 20, QSizePolicy.Fixed, QSizePolicy.Minimum)

        self.horizontalLayout_9.addItem(self.horizontalSpacer_3)


        self.verticalLayout_2.addWidget(self.fontDirLabelFrame)

        self.fontDirFrame = QFrame(self.leftFrame)
        self.fontDirFrame.setObjectName(u"fontDirFrame")
        self.fontDirFrame.setFrameShape(QFrame.NoFrame)
        self.fontDirFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_8 = QHBoxLayout(self.fontDirFrame)
        self.horizontalLayout_8.setSpacing(0)
        self.horizontalLayout_8.setObjectName(u"horizontalLayout_8")
        self.horizontalLayout_8.setContentsMargins(0, 5, 0, 0)
        self.fontDirList = QListWidget(self.fontDirFrame)
        self.fontDirList.setObjectName(u"fontDirList")
        font1 = QFont()
        font1.setFamily(u"Source Code Pro")
        font1.setPointSize(12)
        self.fontDirList.setFont(font1)
        self.fontDirList.setFrameShape(QFrame.NoFrame)
        self.fontDirList.setSelectionRectVisible(True)

        self.horizontalLayout_8.addWidget(self.fontDirList)


        self.verticalLayout_2.addWidget(self.fontDirFrame)

        self.verticalSpacer = QSpacerItem(20, 100, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.verticalLayout_2.addItem(self.verticalSpacer)

        self.frame = QFrame(self.leftFrame)
        self.frame.setObjectName(u"frame")
        self.frame.setFrameShape(QFrame.StyledPanel)
        self.frame.setFrameShadow(QFrame.Raised)

        self.verticalLayout_2.addWidget(self.frame)


        self.horizontalLayout.addWidget(self.leftFrame)

        self.rightFrame = QFrame(self.mainFrame)
        self.rightFrame.setObjectName(u"rightFrame")
        self.rightFrame.setFrameShape(QFrame.NoFrame)
        self.rightFrame.setFrameShadow(QFrame.Raised)
        self.horizontalLayout_7 = QHBoxLayout(self.rightFrame)
        self.horizontalLayout_7.setSpacing(0)
        self.horizontalLayout_7.setObjectName(u"horizontalLayout_7")
        self.horizontalLayout_7.setContentsMargins(30, 50, 30, 30)
        self.textInput = QPlainTextEdit(self.rightFrame)
        self.textInput.setObjectName(u"textInput")
        font2 = QFont()
        font2.setFamily(u"FreeMono")
        font2.setPointSize(48)
        self.textInput.setFont(font2)

        self.horizontalLayout_7.addWidget(self.textInput)


        self.horizontalLayout.addWidget(self.rightFrame)


        self.verticalLayout.addWidget(self.mainFrame)

        TypeWriter.setCentralWidget(self.centralwidget)

        self.retranslateUi(TypeWriter)

        QMetaObject.connectSlotsByName(TypeWriter)
    # setupUi

    def retranslateUi(self, TypeWriter):
        TypeWriter.setWindowTitle(QCoreApplication.translate("TypeWriter", u"MainWindow", None))
        self.closeButton.setText("")
        self.minButton.setText("")
        self.maxButton.setText("")
        self.loadFontLabel.setText(QCoreApplication.translate("TypeWriter", u"Load Font ", None))
        self.fontButton.setText("")
        self.fontLabel.setText(QCoreApplication.translate("TypeWriter", u"  Free Mono", None))
        self.fontDirLabel.setText(QCoreApplication.translate("TypeWriter", u"Open Folder  ", None))
        self.fontDirButton.setText("")
    # retranslateUi

