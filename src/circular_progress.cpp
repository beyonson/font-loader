#include "circular_progress.h"

CircularProgress::CircularProgress(QWidget *parent) : QWidget(parent)
{
	this->resize(this->width,this->height);
}

void CircularProgress::paintEvent(QPaintEvent *)
{
	// set progress values
	int width 	= this->width - this->progWidth;
	int height 	= this->height - this->progWidth;
	int margin 	= this->progWidth / 2;
	int value 	= this->value * 360 / this->maxValue;

	// create painter
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	// create rectangle
	QRectF rect = QRectF(0,0,this->width,this->height);
	painter.setPen(Qt::NoPen);
	painter.drawRect(rect);
	painter.setFont(QFont("Segoe UI", this->fontSize));

	// create pen
	QPen pen = QPen();
	pen.setColor(this->progColor);
	pen.setWidth(this->progWidth);
	// round cap
	if (this->progRoundedCap)
		pen.setCapStyle(Qt::RoundCap);
	
	// create arc
	painter.setPen(pen);
	painter.drawArc(margin, margin, width, height, -90*16, -value*16); // 360 degreed = 5760 in Qt

	// create text
	QString percent = QString::fromStdString(std::to_string(this->value) + this->suffix);
	painter.drawText(rect, Qt::AlignCenter, percent);

	// close painter
	painter.end();
}

void CircularProgress::setValue(int newValue)
{
	// change progress value
	this->value = newValue;
	// repaint bar
	this->update();
}

void CircularProgress::addShadow(bool enable)
{
	if (enable)
	{
		this->shadow->setBlurRadius(15);
		this->shadow->setXOffset(0);
		this->shadow->setYOffset(0);
		this->shadow->setColor(QColor(0,0,0,120));
		this->setGraphicsEffect(this->shadow);
	}
}
