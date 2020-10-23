#include "QtApp.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

#include "RectItem.h"

int main( int argc, char* argv[] )
{
    QApplication a( argc, argv );


    // Creating scene and item
    QGraphicsScene* pScene = new QGraphicsScene();
    CRectItem* pRectItem = new CRectItem();

    pRectItem->setRect( 0, 0, 100, 100 );
    pScene->addItem( pRectItem );

    // Make rect focusable and focus it
    pRectItem->setFlag( QGraphicsItem::ItemIsFocusable );
    pRectItem->setFocus();

    QGraphicsView* pView = new QGraphicsView( pScene );

    pView->show();

    return a.exec();
}