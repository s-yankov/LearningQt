///////////////////
/// Score.h
///
#pragma once

#include <QtWidgets/QGraphicsTextItem>

///////////////////
/// CScore
class CScore : public QGraphicsTextItem
{
//////////////////////////////
/// Constructor / Destructor
public:
	CScore( QGraphicsItem* pParent = 0 );

///////////////////////////
/// Methods
public:
	void increase();
	long getScore();

//////////////////////////
/// Members
private:
	QString m_strText { "Score: " };
	long m_lScore {};

};

