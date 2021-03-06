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

CPlayer::CPlayer( QGraphicsItem* pParent ) : QObject(), QGraphicsPixmapItem( pParent )
{
    setPixmap( QPixmap( ":/images/player_resized.png" ) );
    QObject::connect( m_pBulletTimer, SIGNAL( timeout() ), this, SLOT( shootBullet() ) );
}

void CPlayer::keyPressEvent( QKeyEvent* pKeyEvent )
{
    int nKeyPressed { pKeyEvent->key() };
    switch ( nKeyPressed )
    {
    case Qt::Key_Left:
    {
        if ( pos().x() > 0 )
        {
            setPos( x() - 15, y() );
        }
        break;
    }
    case Qt::Key_Right:
    {
        // TODO: Find a better way to get view's max width
        if ( pos().x() + boundingRect().width() < 800 )
        {
            setPos( x() + 15, y() );
        }
        break;
    }
    case Qt::Key_Space:
    {
        shootBullet();
        m_pBulletTimer->start( 500 );
        break;
    }
    default:
        break;
    }
}

void CPlayer::keyReleaseEvent( QKeyEvent* pKeyEvent )
{
    int nKeyReleased { pKeyEvent->key() };
    if ( nKeyReleased == Qt::Key_Space )
    {
        if ( m_pBulletTimer->isActive() )
        {
            m_pBulletTimer->stop();
        }
    }
}

void CPlayer::shootBullet()
{
    m_pMediaPlayer->setMedia( QUrl( "qrc:/sounds/bullet.mp3" ) );
    m_pMediaPlayer->play();
    CBullet* pBullet { new CBullet() };
    pBullet->setPos( x() + boundingRect().width() / 2 - pBullet->boundingRect().width() / 2, y() - pBullet->boundingRect().height() );
    scene()->addItem( pBullet );
}

void CPlayer::spawnEnemy()
{
    CEnemy* pEnemy { new CEnemy() };
    scene()->addItem( pEnemy );
}