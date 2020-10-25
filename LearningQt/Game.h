///////////////////
/// Game.h
///
#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QMediaPlayer>

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

/////////////////////////////
/// Members
private:
    QGraphicsScene* m_pScene        { new QGraphicsScene() };
    CPlayer*        m_pPlayer       { new CPlayer() };
    CScore*         m_pScore        { new CScore() };
    CHealth*        m_pHealth       { new CHealth() };
    QMediaPlayer*   m_pMediaPlayer  { new QMediaPlayer() };
    //Score* score;
    //Health* health;

};

