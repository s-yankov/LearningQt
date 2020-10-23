#include "RectItem.h"

#include <QDebug>

void CRectItem::keyPressEvent( QKeyEvent* pEvent )
{
    if ( pEvent->key() == Qt::Key_Left )
    {
        setPos( x() - 10, y() );
    }
    else if ( pEvent->key() == Qt::Key_Right )
    {
        setPos( x() + 10, y() );
    }
    else if ( pEvent->key() == Qt::Key_Up )
    {
        setPos( x(), y() - 10 );
    }
    else if ( pEvent->key() == Qt::Key_Down )
    {
        setPos( x(), y() + 10 );
    }

    qDebug() << "Key pressed";
}
