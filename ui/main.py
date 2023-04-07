import sys
import os
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from circular_progress import CircularProgress
from ui_newnew import Ui_TypeWriter

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
    window = MainWindow()

    sys.exit(app.exec())