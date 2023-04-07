import sys
import os
import subprocess
from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

from circular_progress import CircularProgress
from ui_newnew import Ui_TypeWriter
from ui_splash_screen import Ui_SplashScreen

counter = 0

class SplashScreen(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        # create splash screen
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.setAttribute(Qt.WA_TranslucentBackground)
        self.ui = Ui_SplashScreen()
        self.ui.setupUi(self)

        # configure circular progress
        self.progress = CircularProgress()
        self.progress.width = 270
        self.progress.height = 270
        self.progress.value = 0
        self.progress.fontSize = 30
        self.progress.setFixedSize(self.progress.width, self.progress.height)
        self.progress.move(15,15)
        self.progress.addShadow(True)
        self.progress.setParent(self.ui.centralwidget)
        self.progress.show()

        # create timer
        self.timer = QTimer()
        self.timer.timeout.connect(self.update)
        self.timer.start(30)

        self.show()

        # run font loader
        subprocess.Popen('../build/font-loader ../fonts/DroidSansMono.ttf', shell=True)

    # counter process for loading font
    def update(self):
        global counter

        self.progress.setValue(counter)

        if counter >= 100:
            self.timer.stop()
            self.main = MainWindow()
            self.main.show()
            self.close()

        counter += 1


class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.setAttribute(Qt.WA_TranslucentBackground)
        self.ui = Ui_TypeWriter()
        self.ui.setupUi(self)

        self.show()

    def changeValue(self, value):
        self.progress.setValue(value)

    
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = SplashScreen()

    sys.exit(app.exec_())