///////////////////
/// Enemy.h
///
#pragma once

#include <QtWidgets/QGraphicsRectItem>
#include <QObject>

///////////////////
/// CEnemy
class CEnemy : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

/////////////////////////////
/// Constructor / Destructor
public:
	CEnemy();

/////////////////////////////
/// Methods (Slots)
public slots:
	void move();

};

