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
    CRectItem* pPlayer = new CRectItem();

    pPlayer->setRect( 0, 0, 100, 100 );
    pScene->addItem( pPlayer );

    // Make rect focusable and focus it
    pPlayer->setFlag( QGraphicsItem::ItemIsFocusable );
    pPlayer->setFocus();

    QGraphicsView* pView = new QGraphicsView( pScene );

    pView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    pView->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    pView->show();
    pView->setFixedSize( 800, 600 );
    pView->setSceneRect( 0, 0, 800, 600 );
    pPlayer->setPos( pView->width() / 2 - pPlayer->rect().width() / 2, pView->height() - pPlayer->rect().height() - 3 );

    return a.exec();
}