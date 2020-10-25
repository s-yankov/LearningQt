///////////////////
/// Enemy.cpp
///
#include "Enemy.h"

#include <QTimer>
#include <QtWidgets/QGraphicsScene>
#include <stdlib.h>

#define ENEMY_RECT_WIDTH	100
#define ENEMY_RECT_HEIGHT	100

CEnemy::CEnemy()
{
	setRect( 0, 0, ENEMY_RECT_WIDTH, ENEMY_RECT_HEIGHT );
	int nRandomNumber = rand() % 700;
	setPos( nRandomNumber, 0 );

	QTimer* pTimer { new QTimer() };
	connect( pTimer, SIGNAL( timeout() ), this, SLOT( move() ) );
	pTimer->start( 50 );
}

void CEnemy::move()
{
	setPos( x(), y() + 5 );

	if ( pos().y() + rect().height() < 0 )
	{
		scene()->removeItem( this );
		delete this;
	}
}
