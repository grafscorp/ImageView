#include "imagebox.h"
#include "ui_imagebox.h"

ImageBox::ImageBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageBox)
{
    ui->setupUi(this);

}
ImageBox::ImageBox( QString imagePath,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageBox), imagePath(imagePath)
{
    ui->setupUi(this);

    if (imagePath == "") throw EMPTY_FILE_PATH;

    pixmap = new QPixmap(this->imagePath);
    ui->image->setPixmap(pixmap->copy());
}


ImageBox::~ImageBox()
{
    delete ui;
}

void ImageBox::loadPixmap(QString newImagePath)
{
    QPixmap newPixmap = QPixmap(newImagePath);
    ui->image->setPixmap(newPixmap);
    QFileInfo fileInfo(newImagePath);
    ui->ImageGroupBox->setTitle(fileInfo.fileName());
}


void ImageBox::on_show_all_button_clicked()
{

}


void ImageBox::on_fullScreenButton_clicked()
{

}

