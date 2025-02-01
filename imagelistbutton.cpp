#include "imagelistbutton.h"
#include "ui_imagelistbutton.h"

ImageListButton::ImageListButton(QString imagePath,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageListButton), imagePath(imagePath)
{
    ui->setupUi(this);
    QPixmap pixmap(imagePath);
    QIcon imageButtonIcon(pixmap);
    ui->ImageButton->setIcon(imageButtonIcon);
}

ImageListButton::~ImageListButton()
{
    delete ui;
}

void ImageListButton::on_ImageButton_clicked()
{
    emit clicked(imagePath);
}

