///////////////////
/// Player.h
///
#pragma once

#include <QtWidgets/QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

///////////////////
/// CPlayer
class CPlayer : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

////////////////////////////////////////
/// Constructor / Destructor
public:
	CPlayer();


///////////////////
/// Methods
public:
	/// <summary>
	/// Detects a key press event
	/// </summary>
	/// <param name="pEvent">*QKeyEvent</param>
	void keyPressEvent( QKeyEvent* pEvent );


///////////////////
/// Methods (Slots)
public slots:
	/// <summary>
	/// Creates and adds enemies to scene
	/// </summary>
	void spawnEnemy();
};

