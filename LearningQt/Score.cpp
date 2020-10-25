///////////////////
/// Score.cpp
///
#include "Score.h"

#include <QFont>

#define SCORE_TEXT_WIDTH 100

CScore::CScore( QGraphicsItem* pParent ) : QGraphicsTextItem( pParent )
{
    setTextWidth( SCORE_TEXT_WIDTH );
    setPlainText( m_strText + QString::number( m_lScore ) );
    setDefaultTextColor( Qt::blue );
    setFont( QFont( "times", 16 ) );
}

void CScore::increase()
{
    m_lScore++;
    setPlainText( m_strText + QString::number( m_lScore ) );
}

long CScore::getScore()
{
    return m_lScore;
}
