///////////////////
/// Game.h
///
#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QMediaPlayer>
#include <QTimer>

#include "Player.h"
#include "Score.h"
#include "Health.h"

class CGame : public QGraphicsView
{
/////////////////////////////
/// Constructor / Destructor
public:
    /// <summary>
    /// Text representing the score of the player
    /// </summary>
    /// <param name="pParent"></param>
    CGame( QWidget* pParent = 0 );

/////////////////////////////
/// Methods
public:
    /// <returns>Reference to player CScore object</returns>
    CScore&     getScore();
    /// <returns>Reference to player CHealth object</returns>
    CHealth&    getHealth();

    void mouseMoveEvent( QMouseEvent* pMouseEvent );
    void mousePressEvent( QMouseEvent* pMouseEvent );
    void mouseReleaseEvent( QMouseEvent* pMouseEvent );

/////////////////////////////
/// Members
private:
    QGraphicsScene  m_oScene        {};
    CPlayer         m_oPlayer       {};
    CScore          m_oScore        {};
    CHealth*        m_pHealth       { new CHealth() };
    QMediaPlayer*   m_pMediaPlayer  { new QMediaPlayer() };
    QPixmap         m_oBackground   { ":/images/bg_resized.jpg" };
    QTimer*         m_pBulletTimer  { new QTimer() };

};

