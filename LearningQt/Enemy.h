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
	/// <summary>
	/// <para>Sets width and height</para>
	/// <para>Sets a random position</para>
	/// <para>Calls move() method of this class</para>
	/// </summary>
	CEnemy();

/////////////////////////////
/// Methods (Slots)
public slots:
	/// <summary>
	/// <para>Checks for collision with player and detects player's health</para>
	/// <para>Starts moving the enemy object downside</para>
	/// </summary>
	void move();

};

