///////////////////
/// Game.h
///
#include "Game.h"

#include <QTimer>
#include <QDebug>

#include "Enemy.h"

#define GAME_VIEW_WIDTH     800
#define GAME_VIEW_HEIGHT    600

CGame::CGame( QWidget* pParent )
{
    // Create scene with the size of the view
    m_pScene->setSceneRect( 0, 0, GAME_VIEW_WIDTH, GAME_VIEW_HEIGHT );
    setScene( m_pScene );

    // Set fixed size for the view
    setFixedSize( GAME_VIEW_WIDTH, GAME_VIEW_HEIGHT );

    // Create player in the middle of the bottom side of the view
    // Make it focusable and focus it
    m_pScene->addItem( m_pPlayer );
    m_pPlayer->setPos( GAME_VIEW_WIDTH / 2 - m_pPlayer->rect().width() / 2, GAME_VIEW_HEIGHT - m_pPlayer->rect().height() - 3 );
    m_pPlayer->setFlag( QGraphicsItem::ItemIsFocusable );
    m_pPlayer->setFocus();

    // Add score to the scene
    m_pScore->setPos( x(), y() );
    m_pScene->addItem( m_pScore );

    m_pHealth->setPos( x() + (qreal)GAME_VIEW_WIDTH - m_pHealth->textWidth(), y() );
    m_pScene->addItem( m_pHealth );

    // Disable horizontal and vertical scrolling
    setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    // Add enemies
    QTimer* pTimer { new QTimer() };
    QObject::connect( pTimer, SIGNAL( timeout() ), m_pPlayer, SLOT( spawnEnemy() ) );
    pTimer->start( 2500 );
}

CScore& CGame::getScore()
{
    return *m_pScore;
}

CHealth& CGame::getHealth()
{
    return *m_pHealth;
}
