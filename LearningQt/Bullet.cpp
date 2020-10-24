///////////////////
/// Bullet.cpp
///
#include "Bullet.h"

#include <QTimer>
#include <QtWidgets/QGraphicsScene>

CBullet::CBullet()
{
	setRect( 0, 0, 10, 50 );

	QTimer* pTimer = new QTimer();
	connect( pTimer, SIGNAL( timeout() ), this, SLOT( move() ) );
	pTimer->start( 50 );
}

void CBullet::move()
{
	setPos( x(), y() - 10 );

	if ( pos().y() + rect().height() < 0 )
	{
		scene()->removeItem( this );
		delete this;
	}
}
