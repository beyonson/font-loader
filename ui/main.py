import sys
import os
import subprocess
import glob

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

from circular_progress import CircularProgress
from ui_typewriter import Ui_TypeWriter
from ui_splash_screen import Ui_SplashScreen

counter     = 0
fontFolder  = ''
selectedFont= ''

class SplashScreen(QMainWindow):
    def __init__(self, startup):
        QMainWindow.__init__(self)
        # create splash screen
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.setAttribute(Qt.WA_TranslucentBackground)
        self.ui = Ui_SplashScreen()
        self.ui.setupUi(self)
        self.ui.fontSelected.setText("Font Selected: Free Mono")

        # configure circular progress
        self.progress               = CircularProgress()
        self.progress.width         = 270
        self.progress.height        = 270
        self.progress.value         = 0
        self.progress.fontSize      = 30
        self.progress.progressColor = 0xa6adc8
        self.progress.textColor     = 0xa6adc8
        self.progress.setFixedSize(self.progress.width, self.progress.height)
        self.progress.move(15,15)
        self.progress.addShadow(True)
        self.progress.setParent(self.ui.centralwidget)
        self.progress.show()

        if startup:
            # create timer
            self.timer = QTimer()
            self.timer.timeout.connect(self.update)
            self.timer.start(25)
            # run font loader
            subprocess.Popen('../build/font-loader ../fonts/FreeMono.ttf', shell=True)

        self.show()

    # counter process for loading font
    def update(self):
        global counter

        self.progress.setValue(counter)

        if counter >= 100:
            self.timer.stop()
            self.main = MainWindow()
            self.main.show()
            counter = 0
            self.close()

        counter += 1

    def setFontName(self, name):
        self.ui.fontSelected.setText("Font Selected: " + name)

    def setProgressValue(self, value):
        self.progress.setValue(value)


class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.setAttribute(Qt.WA_TranslucentBackground)
        self.ui = Ui_TypeWriter()
        self.ui.setupUi(self)
        self.ui.fontDirSelFrame.hide()

        # set text edit format
        fmt = QTextCharFormat()
        fmt.setFontCapitalization(QFont.AllUppercase)
        self.ui.textInput.setCurrentCharFormat(fmt)

        # connect navigation buttons
        self.ui.closeButton.clicked.connect(self.close)
        self.ui.minButton.clicked.connect(self.showMinimized)
        self.ui.minButton.clicked.connect(self.showMaximized)

        # connect other buttons
        self.ui.fontButton.clicked.connect(self.uploadFont)
        self.ui.fontDirButton.clicked.connect(self.openFolder)
        self.ui.fontDirSelButton.clicked.connect(self.setSelectedFont)
        self.ui.fontDirList.currentRowChanged.connect(self.selectFont)
        self.ui.textInput.textChanged.connect(self.writeToFile)
        self.ui.resetButton.clicked.connect(self.sendResetSignal)

        self.show()

    def writeToFile(self):
        if len(self.ui.textInput.toPlainText()) > 0:
            textFile = open("../../typedText.txt", "a")
            asciiNum = ord(self.ui.textInput.toPlainText()[-1])

            if (asciiNum == 32):
                textFile.write("_")
            elif (asciiNum == 10):
                textFile.write(">")
            else:
                textFile.write(chr(asciiNum))
            
            textFile.close()

    def changeValue(self, value):
        self.progress.setValue(value)

    def mousePressEvent(self, event):
        self.oldPosition = event.globalPos()

    def mouseMoveEvent(self, event):
        delta = QPoint(event.globalPos() - self.oldPosition)
        self.move(self.x() + delta.x(), self.y() + delta.y())
        self.oldPosition = event.globalPos()

    def openFolder(self):
        global fontFolder

        newFolder = QFileDialog.getExistingDirectory(None, 'Select a folder:', '../', QFileDialog.ShowDirsOnly)

        try:
            fonts = os.listdir(newFolder)
        except:
            print("ERROR: no directory selected")
        else:
            fontFolder = newFolder
            self.ui.fontDirList.clear()
            for font in fonts:
                self.ui.fontDirList.addItem(font)

    def selectFont(self):
        global selectedFont

        selectedFont = self.ui.fontDirList.currentItem().text()
        self.ui.fontDirSelLabel.setText("Set " + selectedFont)
        self.ui.fontDirSelFrame.show()

    def sendResetSignal(self):
        textFile = open("../../typedText.txt", "a")
        textFile.write("^")
        textFile.close()

        self.ui.textInput.clear()

    def setSelectedFont(self):
        global fontFolder, selectedFont
        # load font from file
        fontPath = fontFolder + "/" + selectedFont

        id = QFontDatabase.addApplicationFont(fontPath)
        if id < 0: 
            print("ERROR: failed to load Qt font")
            return
        families = QFontDatabase.applicationFontFamilies(id)

        # create parent frame to block buttons
        self.progressParent = QFrame()
        self.progressParent.setParent(self.ui.centralwidget)
        self.progressParent.setStyleSheet("background-color: transparent")
        self.progressParent.resize(800,600)

        # configure circular progress
        self.progress= SplashScreen(False)
        self.progress.setFontName(families[0])

        self.layout = QVBoxLayout()
        self.layout.addWidget(self.progress, Qt.AlignCenter, Qt.AlignCenter)
        self.progressParent.setLayout(self.layout)
        self.progressParent.show()

        # create timer
        self.timer = QTimer()
        self.timer.timeout.connect(self.update)
        self.timer.start(25)

        # run font loader
        subprocess.Popen('../build/font-loader ' + fontPath, shell=True)
        
        # update UI
        self.ui.textInput.clear()
        self.ui.textInput.setFont(QFont(families[0], 48))
        self.ui.fontLabel.setText("  " + families[0])

    def uploadFont(self):
        fontName = QFileDialog.getOpenFileName(QStackedWidget(), 'open file', '../fonts', 'ttf files  (*.ttf)')

        # load font from file
        id = QFontDatabase.addApplicationFont(str(fontName[0]))
        if id < 0: 
            print("ERROR: failed to load Qt font")
            return
        families = QFontDatabase.applicationFontFamilies(id)

        # create parent frame to block buttons
        self.progressParent = QFrame()
        self.progressParent.setParent(self.ui.centralwidget)
        self.progressParent.setStyleSheet("background-color: transparent")
        self.progressParent.resize(800,600)

        self.progress= SplashScreen(False)
        self.progress.setFontName(families[0])

        self.layout = QVBoxLayout()
        self.layout.addWidget(self.progress, Qt.AlignCenter, Qt.AlignCenter)
        self.progressParent.setLayout(self.layout)
        self.progressParent.show()

        # create timer
        self.timer = QTimer()
        self.timer.timeout.connect(self.update)
        self.timer.start(25)

        # run font loader
        subprocess.Popen('../build/font-loader ' + fontName[0], shell=True)
        
        # update UI
        self.ui.textInput.clear()
        self.ui.textInput.setFont(QFont(families[0], 48))
        self.ui.fontLabel.setText("  " + families[0])

    # counter process for loading font
    def update(self):
        global counter

        self.progress.setProgressValue(counter)
        if counter >= 100:
            self.timer.stop()
            self.progressParent.close()
            counter = 0
            self.ui.fontDirSelFrame.hide()

        counter += 1
    
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = SplashScreen(True)

    sys.exit(app.exec_())