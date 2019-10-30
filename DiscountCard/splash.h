#ifndef SPLASH_H
#define SPLASH_H

#include <QDialog>
#include <QSplashScreen>

class QPixmap;

class Splash : public QDialog
{
    Q_OBJECT
public:
    Splash();
    //~Splash();
    int Init();
    static Splash* createSplash();
    void Show();
public slots:
    void slotShow(bool show);

private:
    QPixmap m_pixmap;
    QSplashScreen *m_splashScreen;
    static const int LOAD_TIME_MSEC = 1 * 1000;
    static const int PROGRESS_X_PX = 272;
    static const int PROGRESS_Y_PX = 333;
    static const int PROGRESS_WIDTH_PX = 310;
    static const int PROGRESS_HEIGHT_PX = 28;

signals:
    void SFinished(bool);
};

#endif // SPLASH_H
