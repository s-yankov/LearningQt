///////////////////
/// Game.h
///
#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

#include "Player.h"
#include "Score.h"

class CGame : public QGraphicsView
{
/////////////////////////////
/// Constructor / Destructor
public:
    CGame( QWidget* pParent = 0 );


/////////////////////////////
/// Members
private:
    QGraphicsScene* m_pScene    { new QGraphicsScene() };
    CPlayer*        m_pPlayer   { new CPlayer() };
    CScore*         m_pScore    { new CScore() };
    //Score* score;
    //Health* health;

};

