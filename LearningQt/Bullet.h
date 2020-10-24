///////////////////
/// Bullet.h
///
#pragma once

#include <QtWidgets/QGraphicsRectItem>
#include <QObject>

/// <summary>
/// <para>CBullet</para>
/// <para>Inherits:</para>
/// QObject, QGraphicsRectItem
/// </summary>
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

