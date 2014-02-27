#pragma once

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
