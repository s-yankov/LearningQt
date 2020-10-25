///////////////////
/// Health.h
///
#pragma once

#include <QtWidgets/QGraphicsTextItem>

///////////////////
/// CHealth
class CHealth : public QGraphicsTextItem
{
	//////////////////////////////
	/// Constructor / Destructor
public:
	CHealth( QGraphicsItem* pParent = 0 );

	///////////////////////////
	/// Methods
public:
	void decrease();
	short getHealth();

	//////////////////////////
	/// Members
private:
	QString m_strText { "Health: " };
	short m_sHealth { 100 };

};

