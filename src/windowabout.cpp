#include "windowabout.h"
#include "ui_windowabout.h"

WindowAbout::WindowAbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowAbout)
{
    ui->setupUi(this);
}

WindowAbout::~WindowAbout()
{
    delete ui;
}
