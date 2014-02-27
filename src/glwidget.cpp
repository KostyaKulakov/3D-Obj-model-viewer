#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLWidget::loadfile(QString path)
{
    // Функция получения файла.
}

void GLWidget::initializeGL()
{
    glClearColor(1, 1, 1, 1);
}

void GLWidget::paintGL()
{

}

void GLWidget::resizeGL(int w, int h)
{

}
