///////////////////
/// RectItem.h
///
#pragma once

#include <QtWidgets/QGraphicsRectItem>
#include <QKeyEvent>

///////////////////
/// CRectItem
class CRectItem : public QGraphicsRectItem
{
///////////////////
/// Methods
public:
	/// <summary>
	/// Detects a key press event
	/// </summary>
	/// <param name="pEvent">*QKeyEvent</param>
	void keyPressEvent( QKeyEvent* pEvent );
};

