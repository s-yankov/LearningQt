///////////////////
/// Bullet.cpp
///
#include "Bullet.h"

#include <QTimer>
#include <QList>

#include "Enemy.h"
#include "Game.h"

extern CGame* g_pGame;

CBullet::CBullet( QGraphicsItem* pParent ) : QObject(), QGraphicsPixmapItem( pParent )
{
	setPixmap( QPixmap( ":/images/bullet_resized.png" ) );

	QTimer* pTimer { new QTimer() };
	connect( pTimer, SIGNAL( timeout() ), this, SLOT( move() ) );
	pTimer->start( 20 );
}

void CBullet::move()
{
	QList<QGraphicsItem*> pCollidingItems = collidingItems();
	for ( int_fast64_t i {}; i < pCollidingItems.size(); i++ )
	{
		if ( typeid( *( pCollidingItems[ i ] ) ) == typeid( CEnemy ) )
		{
			g_pGame->getScore().increase();
			g_pGame->scene()->removeItem( pCollidingItems[ i ] );
			g_pGame->scene()->removeItem( this );
			delete pCollidingItems[ i ];
			delete this;
			return;
		}
	}

	setPos( x(), y() - 15 );

	if ( pos().y() + boundingRect().height() < 0 )
	{
		g_pGame->scene()->removeItem( this );
		delete this;
	}
}
