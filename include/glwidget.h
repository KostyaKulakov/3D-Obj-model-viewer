#pragma once

#include <QGLWidget>
#include <QTimer>
#include <QMouseEvent>
#include <GL/glu.h>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void     loadfile(QString path);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent* pe);
    void mouseMoveEvent(QMouseEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);
    void wheelEvent(QWheelEvent* pe);
    void keyPressEvent(QKeyEvent* pe);

private:
   void scale_plus();
   void scale_minus();
   void rotate_up();
   void rotate_down();
   void rotate_left();
   void rotate_right();
   void translate_down();
   void translate_up();
   void defaultScene();

   GLfloat xRot;
   GLfloat yRot;
   GLfloat zRot;
   GLfloat zTra;
   GLfloat nSca;

   QPoint ptrMousePosition;
   QTimer timer;
};
