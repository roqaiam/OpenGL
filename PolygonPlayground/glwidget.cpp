#include "glwidget.h"

glWidget::glWidget(QWidget *parent) :
    QGLWidget(parent)
{
    isRotate = false;
    timer=NULL;
}

void glWidget::Run()
{
    if(!timer){
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()),
                this, SLOT(next()));
        timer->start(5); //in ms
    }
}

void glWidget::Stop()
{
    if(timer) {
        delete timer;
        timer = NULL;
    }
}


void glWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int n = 0; n < PolyBots.size(); ++n) {
//        glTranslatef(P);
//        glRotatef(PolyBots[n].angular_v_f, 0.0f, 0.0f, 0.0f);
        glColor3f(PolyBots[n].color[0],PolyBots[n].color[1],PolyBots[n].color[2]);
        glBegin(GL_POLYGON);
        for (int i = 0; i < PolyBots[n].size(); ++i)
            glVertex3f(PolyBots[n][i].x(),PolyBots[n][i].y(),0);
        glEnd();
    }
}

void glWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.5);
}

void glWidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();   // Reset the camera
}

int glWidget::getPolygonCount() const
{
    return PolyBots.size();
}

void glWidget::addPolygon()
{
    PolyBots << Polygon(); //this add new QPolygonF , dynamic?
    qDebug() << "Polybots size : " << PolyBots.size();
    Run();
}

void glWidget::changeRotate()
{
    isRotate = (isRotate ? false : true);
}

void glWidget::changeTranslate()
{
    isTranslate = (isTranslate ? false : true);
}

void glWidget::next()
{
    for (int i = 0; i < PolyBots.size(); ++i)
        PolyBots[i].move(isTranslate,isRotate);
    updateGL(); // this calls paintGL();
}
void glWidget::changeAllColor()
{
    for (int n = 0; n < PolyBots.size(); ++n)
        PolyBots[n].changeColor();
    updateGL();
}

void glWidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()){
    case Qt::Key_Right:
        break;
    case Qt::Key_Left:
        break;
    case Qt::Key_Up: //run when its pressed
        break;
    case Qt::Key_Down: //stops when released
        break;
    case Qt::Key_Space:
        break;
    case Qt::Key_Escape:
        break;
    case Qt::Key_S:
        break;
    case Qt::Key_L:
        break;
    }
}

void glWidget::mousePressEvent(QMouseEvent *e)
{
    ScreenPos = e->windowPos();
}

void glWidget::mouseReleaseEvent(QMouseEvent *e)
{
}
