#ifndef PLAYERSLIDER_H
#define PLAYERSLIDER_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QSlider>

class PlayerSlider : public QSlider
{
    Q_OBJECT
public:
    explicit PlayerSlider(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void mousepress(int value);
    void mouserelease(int value);
public slots:
};

#endif // PLAYERSLIDER_H
