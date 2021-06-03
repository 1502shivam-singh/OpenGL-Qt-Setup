#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class Scene : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);

public slots:
    void setRedColor();
    void setGreenColor();
    void setBlueColor();

private:
    QOpenGLShaderProgram m_program;
    QOpenGLBuffer m_vertPosBuffer;
    int m_uColorLocation;

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};

#endif // SCENE_H
