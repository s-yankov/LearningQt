#include "Score.h"

#include <QFont>

CScore::CScore( QGraphicsItem* pParent ) : QGraphicsTextItem( pParent )
{
    setPlainText( m_strText + QString::number( m_lScore ) );
    setDefaultTextColor( Qt::blue );
    setFont( QFont( "times", 16 ) );
}

void CScore::increase()
{
    m_lScore++;
}

long CScore::getScore()
{
    return m_lScore;
}
