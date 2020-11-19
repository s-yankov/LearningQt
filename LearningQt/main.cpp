#include "QtApp.h"

#include <QtWidgets/QApplication>

#include "Game.h"

// Bad tutorial - bad practice
CGame* g_pGame;

int main( int argc, char* argv[] )
{
    QApplication a( argc, argv );
    QApplication::setOverrideCursor( Qt::BlankCursor );

    g_pGame = new CGame();

    return a.exec();
}