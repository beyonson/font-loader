import sys
import os
from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from circular_progress import CircularProgress

class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        self.resize(500,500)
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.setAttribute(Qt.WA_TranslucentBackground)

        # create container for progress
        self.container = QFrame()
        self.container.setStyleSheet("background-color: transparent")
        self.layout = QVBoxLayout()

        # add slider
        self.slider = QSlider(Qt.Horizontal)
        self.slider.setRange(0,100)
        self.slider.valueChanged.connect(self.changeValue)

        # create circular progress
        self.progress = CircularProgress()
        self.progress.value = 0
        self.progress.fontSize = 30
        self.progress.setMinimumSize(self.progress.width, self.progress.height)

        # add widgets to main window
        self.layout.addWidget(self.progress, Qt.AlignCenter, Qt.AlignCenter)
        self.layout.addWidget(self.slider, Qt.AlignCenter, Qt.AlignCenter)
        self.container.setLayout(self.layout)
        self.setCentralWidget(self.container)

        # manipulate shadow
        self.progress.addShadow(True)

        self.show()

    def changeValue(self, value):
        self.progress.setValue(value)

    
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    sys.exit(app.exec())