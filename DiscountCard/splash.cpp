#include "splash.h"

#include <QTime>
#include <QSplashScreen>
#include <QPainter>

Splash::Splash()
{

}

void Splash::Show()
{
    m_splashScreen->show();

    QTime time;
    time.start();

    QPainter painter;
    QColor color;
    while( time.elapsed() < LOAD_TIME_MSEC )
    {
        const int progress = static_cast< double >( time.elapsed() ) / LOAD_TIME_MSEC * 100.0;
        m_splashScreen->showMessage( QObject::trUtf8( "Загружено: %1%" ).arg( progress ), Qt::AlignBottom | Qt::AlignCenter/*| Qt::AlignRight */);

        painter.begin( &m_pixmap );
        int x = PROGRESS_WIDTH_PX/2;
        int y = m_splashScreen->y() + m_pixmap.height() - 200;
        color.setRgb(progress*1.5,progress*2.5,progress*1.8);
        painter.fillRect( x, y, progress / 60.0 * PROGRESS_WIDTH_PX, PROGRESS_HEIGHT_PX,color );

        painter.end();

        m_splashScreen->setPixmap( m_pixmap );
    }
    qDebug("emit SFinished splash");
    m_splashScreen->close();
    emit SFinished(true);
}

void Splash::slotShow(bool show)
{
    if(show)
    {
       Show();
    }
}

int Splash::Init()
{
    m_pixmap = QPixmap ( ":/img/meat.png" ).scaled(800,600);
    m_splashScreen = new QSplashScreen( m_pixmap);
    m_splashScreen->resize(800,1194);
    return 1;
}

Splash *Splash::createSplash()
{
    return new Splash;
}

//Splash::~Splash()
//{
//    //delete m_splashScreen;
//}
