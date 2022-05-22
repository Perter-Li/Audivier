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
    void mouseMoveEvent(QMouseEvent *ev);
    void leaveEvent(QEvent * e);
signals:
    void mousepress(int value);
    void mouserelease(int value);
    void SliderMouseMove(double value);
    void SliderMouseLeave();

public slots:
};

#endif // PLAYERSLIDER_H
