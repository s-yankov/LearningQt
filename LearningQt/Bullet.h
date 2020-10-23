#pragma once

#include <QtWidgets/QGraphicsRectItem>
#include <QObject>

class CBullet : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
public:
	CBullet();

public slots:
	void move();

};

