///////////////////
/// Bullet.cpp
///
#include "Bullet.h"

#include <QTimer>
#include <QtWidgets/QGraphicsScene>
#include <QList>

#include "Enemy.h"
#include "Game.h"

extern CGame* g_pGame;

CBullet::CBullet()
{
	setRect( 0, 0, 10, 50 );

	QTimer* pTimer { new QTimer() };
	connect( pTimer, SIGNAL( timeout() ), this, SLOT( move() ) );
	pTimer->start( 50 );
}

void CBullet::move()
{
	QList<QGraphicsItem*> pCollidingItems = collidingItems();
	for ( int_fast64_t i {}; i < pCollidingItems.size(); i++ )
	{
		if ( typeid( *( pCollidingItems[ i ] ) ) == typeid( CEnemy ) )
		{
			g_pGame->getScore().increase();
			scene()->removeItem( pCollidingItems[ i ] );
			scene()->removeItem( this );
			delete pCollidingItems[ i ];
			delete this;
			return;
		}
	}

	setPos( x(), y() - 10 );

	if ( pos().y() + rect().height() < 0 )
	{
		scene()->removeItem( this );
		delete this;
	}
}
