///////////////////
/// Enemy.cpp
///
#include "Enemy.h"

#include <QTimer>
#include <QtWidgets/QGraphicsScene>
#include <stdlib.h>

#include "Player.h"
#include "Game.h"

extern CGame* g_pGame;

#define ENEMY_RECT_WIDTH	100
#define ENEMY_RECT_HEIGHT	100

CEnemy::CEnemy( QGraphicsItem* pParent ) : QObject(), QGraphicsPixmapItem( pParent )
{
	setPixmap( QPixmap( ":/images/enemy_resized.png" ) );
	int nRandomNumber = rand() % 700;
	setPos( nRandomNumber, 0 );

	QTimer* pTimer { new QTimer() };
	connect( pTimer, SIGNAL( timeout() ), this, SLOT( move() ) );
	pTimer->start( 50 );
}

void CEnemy::move()
{
	QList<QGraphicsItem*> pCollidingItems = collidingItems();
	for ( int_fast64_t i {}; i < pCollidingItems.size(); i++ )
	{
		if ( typeid( *( pCollidingItems[ i ] ) ) == typeid( CPlayer ) )
		{
			CHealth& oHealth = g_pGame->getHealth();
			oHealth.decrease();
			g_pGame->scene()->removeItem( this );
			delete this;

			if ( oHealth.getHealth() <= 0 )
			{
				g_pGame->close();
			}

			return;
		}
	}
	setPos( x(), y() + 5 );

	if ( pos().y() + boundingRect().height() < 0 )
	{
		scene()->removeItem( this );
		delete this;
	}
}
