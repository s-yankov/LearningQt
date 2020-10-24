///////////////////
/// Bullet.h
///
#pragma once

#include <QtWidgets/QGraphicsRectItem>
#include <QObject>

///////////////////
/// CBullet
class CBullet : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

/////////////////////////////
/// Constructor / Destructor
public:
	CBullet();

/////////////////////////////
/// Methods (Slots)
public slots:
	void move();

};

