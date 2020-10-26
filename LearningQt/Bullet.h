///////////////////
/// Bullet.h
///
#pragma once

#include <QtWidgets/QGraphicsPixmapItem>
#include <QObject>

///////////////////
/// CBullet
class CBullet : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

/////////////////////////////
/// Constructor / Destructor
public:
	/// <summary>
	/// <para>Sets width and height</para>
	/// <para>Sets the starting position to the center of the top side of the player</para>
	/// <para>Calls move() method of this class</para>
	/// </summary>
	CBullet( QGraphicsItem* pParent = 0 );

/////////////////////////////
/// Methods (Slots)
public slots:
	/// <summary>
	/// <para>Checks for collision with enemy</para>
	/// <para>Starts moving the bullet object upside</para>
	/// </summary>
	void move();

};

