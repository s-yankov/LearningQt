#pragma once

#include <QtWidgets/QGraphicsRectItem>
#include <QKeyEvent>

class CRectItem : public QGraphicsRectItem
{
public:
	void keyPressEvent( QKeyEvent* pEvent );
};

