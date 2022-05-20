#ifndef SETVOLUME_H
#define SETVOLUME_H

#include <QWidget>

namespace Ui {
class SetVolume;
}

class SetVolume : public QWidget
{
    Q_OBJECT

public:
    explicit SetVolume(QWidget *parent = nullptr);
    ~SetVolume();

private slots:
    void on_toolButton_clicked();

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::SetVolume *ui;

signals:
    void VolumeSignal(int);
};

#endif // SETVOLUME_H
