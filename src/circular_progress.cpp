#include "circular_progress.h"

CircularProgress::CircularProgress(QWidget *parent) : QWidget(parent)
{
	this->resize(this->width,this->height);
}

void CircularProgress::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QRectF size = QRectF(10,10,100,100);
	painter.setPen(Qt::NoBrush);
	painter.drawRect(size);
}
