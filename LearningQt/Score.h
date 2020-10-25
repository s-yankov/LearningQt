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
	/// <summary>
	/// Increases score by 1
	/// </summary>
	void increase();
	/// <returns>Current score</returns>
	long getScore();

//////////////////////////
/// Members
private:
	QString m_strText { "Score: " };
	long m_lScore {};

};

