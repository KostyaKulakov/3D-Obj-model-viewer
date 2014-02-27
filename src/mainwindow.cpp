#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAbout,         &QAction::triggered, &winabout, &WindowAbout::show);
    connect(ui->actionOpen_obj_model,&QAction::triggered, this,      &MainWindow::loadfile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadfile()
{
    QFileDialog fd;
    const QString filepath =  fd.getOpenFileName(this, "Select model", "", "wavefront format (*.obj)");

    if(filepath.isEmpty())
        return;

    QFileInfo fi(filepath);

    if(fi.completeSuffix() != "obj")
    {
        QMessageBox mb;
        mb.setWindowTitle("Invalid file");
        mb.setText("The file must have the \".obj\" format");
        mb.exec();
        return;
    }
    else if(!fi.isReadable())
    {
        QMessageBox mb;
        mb.setWindowTitle("File Manager");
        mb.setText("Can not open file");
        mb.exec();
        return;
    }

    ui->centralWidget->loadfile(filepath);
}
