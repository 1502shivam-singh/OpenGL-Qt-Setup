#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->sceneWidget->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Maximum);

    connect(ui->btnSetRed, &QPushButton::clicked, ui->sceneWidget, &Scene::setRedColor);
    connect(ui->btnSetGreen, &QPushButton::clicked, ui->sceneWidget, &Scene::setGreenColor);
    connect(ui->btnSetBlue, &QPushButton::clicked, ui->sceneWidget, &Scene::setBlueColor);
}

Widget::~Widget()
{
    delete ui;
}
