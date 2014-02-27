#include "glwidget.h"
#include "math.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, &QTimer::timeout, this, &QGLWidget::updateGL);
    timer.start();

    xRot=-90; yRot=0; zRot=0; zTra=0; nSca=1;
}

void GLWidget::loadfile(QString path)
{
    // Функция получения файла.
}

void GLWidget::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(nSca, nSca, nSca);
    glTranslatef(0.0f, zTra, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot, 0.0f, 0.0f, 1.0f);
}

void GLWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio=(GLfloat)h/(GLfloat)w;

    if (w>=h)
        glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
    else
        glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);

    glViewport(0, 0, (GLint)w, (GLint)h);
}

void GLWidget::mousePressEvent(QMouseEvent* pe)
{
    ptrMousePosition = pe->pos();
}

void GLWidget::mouseReleaseEvent(QMouseEvent* pe)
{
}

void GLWidget::mouseMoveEvent(QMouseEvent* pe)
{
    xRot += 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height();
    zRot += 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width();

    ptrMousePosition = pe->pos();
}

void GLWidget::wheelEvent(QWheelEvent* pe)
{
    if (pe->delta() > 0)
        scale_plus();
    else if(pe->delta() < 0)
        scale_minus();
}

void GLWidget::keyPressEvent(QKeyEvent* pe)
{
    switch (pe->key())
    {
        case Qt::Key_Plus:
            scale_plus();
        break;

        case Qt::Key_Equal:
            scale_plus();
        break;

        case Qt::Key_Minus:
            scale_minus();
        break;

        case Qt::Key_Up:
            rotate_up();
        break;

        case Qt::Key_Down:
            rotate_down();
        break;

        case Qt::Key_Left:
            rotate_left();
        break;

        case Qt::Key_Right:
            rotate_right();
        break;

        case Qt::Key_Z:
            translate_down();
        break;

        case Qt::Key_X:
            translate_up();
        break;

        case Qt::Key_Space:
            defaultScene();
        break;

        case Qt::Key_Escape:
            this->close();
        break;
    }
}

void GLWidget::scale_plus()
{
    nSca = nSca*1.1;
}

void GLWidget::scale_minus()
{
    nSca = nSca/1.1;
}

void GLWidget::rotate_up()
{
    xRot += 1.0;
}

void GLWidget::rotate_down()
{
    xRot -= 1.0;
}

void GLWidget::rotate_left()
{
    zRot += 1.0;
}

void GLWidget::rotate_right()
{
    zRot -= 1.0;
}

void GLWidget::translate_down()
{
    zTra -= 0.05;
}

void GLWidget::translate_up()
{
    zTra += 0.05;
}

void GLWidget::defaultScene()
{
    xRot=-90;
    yRot=0;
    zRot=0;
    zTra=0;
    nSca=1;
}
