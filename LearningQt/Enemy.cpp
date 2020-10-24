///////////////////
/// Enemy.cpp
///
#include "Enemy.h"

#include <QTimer>
#include <QtWidgets/QGraphicsScene>
#include <stdlib.h>

CEnemy::CEnemy()
{
	setRect( 0, 0, 100, 100 );
	int nRandomNumber = rand() % 700;
	setPos( nRandomNumber, 10 );

	QTimer* pTimer = new QTimer();
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
