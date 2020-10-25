///////////////////
/// Health.cpp
///
#include "Health.h"

#include <QFont>

#define HEALTH_TEXT_WIDTH 107

CHealth::CHealth( QGraphicsItem* pParent )
{
    setTextWidth( HEALTH_TEXT_WIDTH );
    setPlainText( m_strText + QString::number( m_sHealth ) );
    setDefaultTextColor( Qt::blue );
    setFont( QFont( "times", 16 ) );
}

void CHealth::decrease()
{
    m_sHealth -= 20;
    setPlainText( m_strText + QString::number( m_sHealth ) );
}

short CHealth::getHealth()
{
    return m_sHealth;
}
