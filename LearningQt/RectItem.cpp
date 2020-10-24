///////////////////
/// RectItem.cpp
///
#include "RectItem.h"

#include <QDebug>
#include <QtWidgets/QGraphicsScene>

#include "Bullet.h"

void CRectItem::keyPressEvent( QKeyEvent* pEvent )
{
    int nKeyPressed = pEvent->key();
    switch ( nKeyPressed )
    {
    case Qt::Key_Left:
    {
        setPos( x() - 10, y() );
        break;
    }
    case Qt::Key_Right:
    {
        setPos( x() + 10, y() );
        break;
    }
    case Qt::Key_Up:
    {
        setPos( x(), y() - 10 );
        break;
    }
    case Qt::Key_Down:
    {
        setPos( x(), y() + 10 );
        break;
    }
    case Qt::Key_Space:
    {
        CBullet* pBullet = new CBullet();
        pBullet->setPos( x(), y() );
        scene()->addItem( pBullet );
        break;
    }
    default:
        break;
    }
}
