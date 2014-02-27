#ifndef WINDOWABOUT_H
#define WINDOWABOUT_H

#include <QWidget>

namespace Ui {
class WindowAbout;
}

class WindowAbout : public QWidget
{
    Q_OBJECT

public:
    explicit WindowAbout(QWidget *parent = 0);
    ~WindowAbout();

private:
    Ui::WindowAbout *ui;
};

#endif // WINDOWABOUT_H
