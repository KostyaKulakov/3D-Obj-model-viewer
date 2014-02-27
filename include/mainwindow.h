#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include "windowabout.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void loadfile();

private:
    WindowAbout winabout;
    Ui::MainWindow *ui;
};
