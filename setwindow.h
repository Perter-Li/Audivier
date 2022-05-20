#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QWidget>

namespace Ui {
class SetWindow;
}

class SetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SetWindow(QWidget *parent = nullptr);
    ~SetWindow();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_3_clicked();

private:
    Ui::SetWindow *ui;
};

#endif // SETWINDOW_H
