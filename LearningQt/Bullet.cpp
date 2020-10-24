///////////////////
/// Bullet.cpp
///
#include "Bullet.h"

#include <QTimer>

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
}
