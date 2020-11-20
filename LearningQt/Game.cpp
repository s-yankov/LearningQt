///////////////////
/// Game.h
///
#include "Game.h"

#include <QTimer>
#include <QDebug>

#include "Enemy.h"
#include "Bullet.h"

#define GAME_VIEW_WIDTH     800
#define GAME_VIEW_HEIGHT    600

CGame::CGame( QWidget* pParent )
{
    // Create scene with the size of the view
    m_oScene.setSceneRect( 0, 0, GAME_VIEW_WIDTH, GAME_VIEW_HEIGHT );
    setScene( &m_oScene );

    // Set background image
    setBackgroundBrush( m_oBackground );

    // Set fixed size for the view
    setFixedSize( GAME_VIEW_WIDTH, GAME_VIEW_HEIGHT );

    // Create player in the middle of the bottom side of the view
    // Make it focusable and focus it
    m_oScene.addItem( &m_oPlayer );
    m_oPlayer.setPos( GAME_VIEW_WIDTH / 2 - m_oPlayer.boundingRect().width() / 2, GAME_VIEW_HEIGHT - m_oPlayer.boundingRect().height() - 3 );
    m_oPlayer.setFlag( QGraphicsItem::ItemIsFocusable );
    m_oPlayer.setFocus();

    // Add score to the scene
    m_oScore.setPos( x(), y() );
    m_oScene.addItem( &m_oScore );

    // Add health to the scene
    m_pHealth->setPos( x() + (qreal)GAME_VIEW_WIDTH - m_pHealth->textWidth(), y() );
    m_oScene.addItem( m_pHealth );

    // Disable horizontal and vertical scrolling
    setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    // Add enemies
    QTimer* pTimer { new QTimer() };
    QObject::connect( pTimer, SIGNAL( timeout() ), &m_oPlayer, SLOT( spawnEnemy() ) );
    pTimer->start( 2500 );

    //Add bullet shooting
    QObject::connect( m_pBulletTimer, SIGNAL( timeout() ), &m_oPlayer, SLOT( shootBullet() ) );

    m_pMediaPlayer->setMedia( QUrl( "qrc:/sounds/bgsound.mp3" ) );
    m_pMediaPlayer->play();

    show();
}

CScore& CGame::getScore()
{
    return m_oScore;
}

CHealth& CGame::getHealth()
{
    return *m_pHealth;
}


void CGame::mouseMoveEvent( QMouseEvent* pMouseEvent )
{
    QPoint& oMousePos = pMouseEvent->pos();
    qreal qMouseX = oMousePos.x();
    qreal qMouseY = oMousePos.y();

    qreal qPlayerX = qMouseX - m_oPlayer.boundingRect().width() / 2;
    qreal qPlayerY = qMouseY - m_oPlayer.boundingRect().height() / 2;
    m_oPlayer.setPos( qPlayerX, qPlayerY );
}

void CGame::mousePressEvent( QMouseEvent* pMouseEvent )
{
    if ( pMouseEvent->button() == Qt::LeftButton && pMouseEvent->type() == QMouseEvent::MouseButtonPress )
    {
        m_oPlayer.shootBullet();
        m_pBulletTimer->start( 500 );
    }
}

void CGame::mouseReleaseEvent( QMouseEvent* pMouseEvent )
{
    if ( pMouseEvent->button() == Qt::LeftButton && pMouseEvent->type() == QMouseEvent::MouseButtonRelease )
    {
        if ( m_pBulletTimer->isActive() )
        {
            m_pBulletTimer->stop();
        }
    }
}