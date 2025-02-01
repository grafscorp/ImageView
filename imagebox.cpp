#include "imagebox.h"
#include "ui_imagebox.h"

ImageBox::ImageBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageBox)
{
    ui->setupUi(this);
}

ImageBox::~ImageBox()
{
    delete ui;
}
