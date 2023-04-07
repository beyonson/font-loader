from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

class CircularProgress(QWidget):
    def __init__(self):
        QWidget.__init__(self)
        # progress properties
        self.value              = 0
        self.width              = 200
        self.height             =200
        self.progressWidth      = 10
        self.progressRoundedCap = True
        self.progressColor      = 0x4988D1
        self.maxValue           = 100
        self.fontFamily         = "Segoe UI"
        self.fontSize           = 12
        self.suffix             = "%"
        self.textColor          = 0x4988D1
        self.enableShadow       = True

        # set default size
        self.resize(self.width, self.height)

    # set progress value
    def setValue(self, value):
        self.value = value
        self.repaint()

    # draw shadow
    def addShadow(self, enable):
        if enable:
            self.shadow = QGraphicsDropShadowEffect(self)
            self.shadow.setBlurRadius(15)
            self.shadow.setXOffset(0)
            self.shadow.setYOffset(0)
            self.shadow.setColor(QColor(0,0,0,120))
            self.setGraphicsEffect(self.shadow)

    # paint event definition, used by qt to render widget
    def paintEvent(self, event):
        # set progress values
        width = self.width - self.progressWidth
        height = self.height - self.progressWidth
        margin = self.progressWidth / 2
        value  = self.value * 360 / self.maxValue

        # make painter
        paint = QPainter()
        paint.begin(self)
        paint.setRenderHint(QPainter.Antialiasing)
        paint.setFont(QFont(self.fontFamily, self.fontSize))

        # create rectangle
        rect = QRect(0, 0, self.width, self.height)
        paint.setPen(Qt.NoPen)
        paint.drawRect(rect)

        # create pen
        pen = QPen()
        pen.setColor(QColor(self.progressColor))
        pen.setWidth(self.progressWidth)
        if self.progressRoundedCap:
            pen.setCapStyle(Qt.RoundCap)

        # draw arc
        paint.setPen(pen)
        paint.drawArc(margin, margin, width, height, -90 * 16, -value * 16)

        # create text
        pen.setColor(QColor(self.textColor))
        paint.setPen(pen)
        paint.drawText(rect, Qt.AlignCenter, f"{self.value}{self.suffix}")

        # close painter
        paint.end()

