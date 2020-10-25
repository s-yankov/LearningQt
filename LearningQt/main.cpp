#include "QtApp.h"

#include <QtWidgets/QApplication>

#include "Game.h"

int main( int argc, char* argv[] )
{
    QApplication a( argc, argv );
    
    CGame* pGame = new CGame();
    pGame->show();

    return a.exec();
}