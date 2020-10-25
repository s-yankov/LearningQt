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
	/// <summary>
	/// Text representing the health of the player
	/// </summary>
	/// <param name="pParent"></param>
	CHealth( QGraphicsItem* pParent = 0 );

	///////////////////////////
	/// Methods
public:
	/// <summary>
	/// Decreases player's health by 20
	/// </summary>
	void decrease();
	/// <returns>Player's current health</returns>
	short getHealth();

	//////////////////////////
	/// Members
private:
	QString	m_strText	{ "Health: " };
	short	m_sHealth	{ 100 };

};

