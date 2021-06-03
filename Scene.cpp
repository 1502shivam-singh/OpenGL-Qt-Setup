#include "Scene.h"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent)
{

}

void Scene::initializeGL()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);

    m_program.create();
    m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/vertexShader.glsl");
    m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/fragmentShader.glsl");
    m_program.link();
    m_program.bind();

    float vertPositions[] = {
        -0.75, -0.5f, 0.f,
        0.75, -0.5f, 0.f,
        -0.75, 0.5f, 0.f,
        0.75f, 0.5f, 0.f
    };
    m_vertPosBuffer.create();
    m_vertPosBuffer.bind();
    m_vertPosBuffer.allocate(vertPositions, sizeof(vertPositions));
    m_program.setAttributeBuffer(0, GL_FLOAT, 0, 3);
    m_program.enableAttributeArray(0);

    m_program.bind();
    m_uColorLocation = m_program.uniformLocation("uColor");
    m_program.setUniformValue(m_uColorLocation, QVector4D(1, 0, 0, 1));
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Scene::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Scene::setRedColor()
{
    m_program.bind();
    m_program.setUniformValue(m_uColorLocation, QVector4D(1, 0, 0, 1));
    update();
}

void Scene::setGreenColor()
{
    m_program.bind();
    m_program.setUniformValue(m_uColorLocation, QVector4D(0, 1, 0, 1));
    update();
}

void Scene::setBlueColor()
{
    m_program.bind();
    m_program.setUniformValue(m_uColorLocation, QVector4D(0, 0, 1, 1));
    update();
}
