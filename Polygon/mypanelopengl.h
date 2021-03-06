#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyPanelOpenGL(QWidget *parent = 0);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    int sides;
    double radius;

signals:

public slots:
    void changeSides(int s);
    void changeRadius(double r);

};

#endif // MYPANELOPENGL_H
