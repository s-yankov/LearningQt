///////////////////
/// Player.h
///
#pragma once

#include <QtWidgets/QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>

///////////////////
/// CPlayer
class CPlayer : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

////////////////////////////////////////
/// Constructor / Destructor
public:
	CPlayer( QGraphicsItem* pParent = 0 );


///////////////////
/// Methods
public:
	/// <summary>
	/// Detects a key press event
	/// </summary>
	/// <param name="pEvent">*QKeyEvent</param>
	void keyPressEvent( QKeyEvent* pKeyEvent );


///////////////////
/// Methods (Slots)
public slots:
	/// <summary>
	/// Creates and adds enemies to scene
	/// </summary>
	void spawnEnemy();
	void shootBullet();


///////////////////
/// Members
private:
	QMediaPlayer* m_pMediaPlayer { new QMediaPlayer() };
};

