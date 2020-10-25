///////////////////
/// Player.cpp
///
#include "Player.h"

#include <QDebug>
#include <QtWidgets/QGraphicsScene>

#include "Bullet.h"
#include "Enemy.h"

#define PLAYER_RECT_WIDTH   100
#define PLAYER_RECT_HEIGTH  100

CPlayer::CPlayer()
{
    setRect( 0, 0, PLAYER_RECT_WIDTH, PLAYER_RECT_HEIGTH );
}

void CPlayer::keyPressEvent( QKeyEvent* pEvent )
{
    int nKeyPressed { pEvent->key() };
    switch ( nKeyPressed )
    {
    case Qt::Key_Left:
    {
        if ( pos().x() > 0 )
        {
            setPos( x() - 10, y() );
        }
        break;
    }
    case Qt::Key_Right:
    {
        // TODO: Find a better way to get view's max width
        if ( pos().x() + rect().width() < 800 )
        {
            setPos( x() + 10, y() );
        }
        break;
    }
    case Qt::Key_Space:
    {
        CBullet* pBullet { new CBullet() };
        pBullet->setPos( x(), y() );
        scene()->addItem( pBullet );
        break;
    }
    default:
        break;
    }
}

void CPlayer::spawnEnemy()
{
    CEnemy* pEnemy { new CEnemy() };
    scene()->addItem( pEnemy );
}