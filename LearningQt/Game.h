///////////////////
/// Game.h
///
#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

#include "Player.h"

class CGame : public QGraphicsView
{
/////////////////////////////
/// Constructor / Destructor
public:
    CGame( QWidget* pParent = 0 );


/////////////////////////////
/// Members
    QGraphicsScene* m_pScene;
    CPlayer* m_pPlayer;
    //Score* score;
    //Health* health;

};

