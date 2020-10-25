///////////////////
/// Game.h
///
#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

#include "Player.h"
#include "Score.h"
#include "Health.h"

class CGame : public QGraphicsView
{
/////////////////////////////
/// Constructor / Destructor
public:
    CGame( QWidget* pParent = 0 );

/////////////////////////////
/// Methods
public:
    CScore&     getScore();
    CHealth&    getHealth();

/////////////////////////////
/// Members
private:
    QGraphicsScene* m_pScene    { new QGraphicsScene() };
    CPlayer*        m_pPlayer   { new CPlayer() };
    CScore*         m_pScore    { new CScore() };
    CHealth*        m_pHealth   { new CHealth() };
    //Score* score;
    //Health* health;

};

