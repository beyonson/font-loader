# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'splash_screenIVXSxt.ui'
##
## Created by: Qt User Interface Compiler version 5.15.9
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *  # type: ignore
from PySide2.QtGui import *  # type: ignore
from PySide2.QtWidgets import *  # type: ignore


class Ui_SplashScreen(object):
    def setupUi(self, SplashScreen):
        if not SplashScreen.objectName():
            SplashScreen.setObjectName(u"SplashScreen")
        SplashScreen.resize(300, 300)
        SplashScreen.setMinimumSize(QSize(300, 300))
        SplashScreen.setMaximumSize(QSize(300, 300))
        self.centralwidget = QWidget(SplashScreen)
        self.centralwidget.setObjectName(u"centralwidget")
        self.centralwidget.setStyleSheet(u"")
        self.verticalLayout = QVBoxLayout(self.centralwidget)
        self.verticalLayout.setSpacing(0)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(10, 10, 10, 10)
        self.container = QFrame(self.centralwidget)
        self.container.setObjectName(u"container")
        self.container.setFrameShape(QFrame.NoFrame)
        self.container.setFrameShadow(QFrame.Raised)
        self.horizontalLayout = QHBoxLayout(self.container)
        self.horizontalLayout.setSpacing(0)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(20, 20, 20, 20)
        self.circleBg = QFrame(self.container)
        self.circleBg.setObjectName(u"circleBg")
        self.circleBg.setStyleSheet(u"QFrame {\n"
"	background-color: #181825;\n"
"	color:  #cdd6f4;\n"
"	border-radius: 120;\n"
"	font: 9pt \"Segoe Ui\";\n"
"}")
        self.circleBg.setFrameShape(QFrame.NoFrame)
        self.circleBg.setFrameShadow(QFrame.Raised)
        self.verticalLayout_2 = QVBoxLayout(self.circleBg)
        self.verticalLayout_2.setSpacing(0)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.texts = QFrame(self.circleBg)
        self.texts.setObjectName(u"texts")
        self.texts.setMaximumSize(QSize(16777215, 180))
        self.texts.setStyleSheet(u"background: none;")
        self.texts.setFrameShape(QFrame.StyledPanel)
        self.texts.setFrameShadow(QFrame.Raised)
        self.verticalLayout_3 = QVBoxLayout(self.texts)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.gridLayout = QGridLayout()
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setContentsMargins(-1, 25, -1, -1)
        self.fontFrame = QFrame(self.texts)
        self.fontFrame.setObjectName(u"fontFrame")
        self.fontFrame.setFrameShape(QFrame.NoFrame)
        self.fontFrame.setFrameShadow(QFrame.Raised)
        self.verticalLayout_4 = QVBoxLayout(self.fontFrame)
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.fontSelected = QLabel(self.fontFrame)
        self.fontSelected.setObjectName(u"fontSelected")
        self.fontSelected.setMinimumSize(QSize(200, 24))
        self.fontSelected.setMaximumSize(QSize(200, 24))
        self.fontSelected.setStyleSheet(u"QLabel {\n"
"	color: #a6adc8;\n"
"	border-radius: 12px;\n"
"	background-color: #6c7086;\n"
"}")
        self.fontSelected.setAlignment(Qt.AlignCenter)

        self.verticalLayout_4.addWidget(self.fontSelected, 0, Qt.AlignHCenter)


        self.gridLayout.addWidget(self.fontFrame, 2, 0, 1, 1)

        self.title = QLabel(self.texts)
        self.title.setObjectName(u"title")
        self.title.setMinimumSize(QSize(0, 30))
        self.title.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.title, 0, 0, 1, 1)

        self.percentFrame = QFrame(self.texts)
        self.percentFrame.setObjectName(u"percentFrame")
        self.percentFrame.setMinimumSize(QSize(0, 60))
        self.percentFrame.setMaximumSize(QSize(16777215, 80))
        self.percentFrame.setFrameShape(QFrame.StyledPanel)
        self.percentFrame.setFrameShadow(QFrame.Raised)

        self.gridLayout.addWidget(self.percentFrame, 1, 0, 1, 1)

        self.loading = QLabel(self.texts)
        self.loading.setObjectName(u"loading")
        self.loading.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.loading, 3, 0, 1, 1)


        self.verticalLayout_3.addLayout(self.gridLayout)


        self.verticalLayout_2.addWidget(self.texts)


        self.horizontalLayout.addWidget(self.circleBg)


        self.verticalLayout.addWidget(self.container)

        SplashScreen.setCentralWidget(self.centralwidget)

        self.retranslateUi(SplashScreen)

        QMetaObject.connectSlotsByName(SplashScreen)
    # setupUi

    def retranslateUi(self, SplashScreen):
        SplashScreen.setWindowTitle(QCoreApplication.translate("SplashScreen", u"Loading", None))
        self.fontSelected.setText(QCoreApplication.translate("SplashScreen", u"Font Selected:", None))
        self.title.setText(QCoreApplication.translate("SplashScreen", u"Whiteboard Typerwriter", None))
        self.loading.setText(QCoreApplication.translate("SplashScreen", u"loading...", None))
    # retranslateUi

