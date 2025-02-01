#include "imagebox.h"
#include "ui_imagebox.h"

ImageBox::ImageBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageBox)
{
    ui->setupUi(this);
    updateStateImageAll();
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

void ImageBox::updateImagePath(QString newImagePath)
{
    imagePath = newImagePath;
    QStringList filters;
    filters << "*.png" << "*.jpg";
    QDir dir = QDir(imagePath);
    imageFilesInPath = dir.entryInfoList(filters, QDir::Files|QDir::NoDotAndDotDot);

    for (int i= 0; i < imageFilesInPath.size(); ++i) {
        ImageListButton* newImageInPath = new ImageListButton(imageFilesInPath.at(i).filePath());
        //newImageInPath->setVisible(allImageShowed);
        ui->all_images_HBOX->addWidget(newImageInPath);
    }
}

void ImageBox::updateStateImageAll()
{
    for (int i = 0; i < ui->all_images_HBOX->count(); ++i) {
        ui->all_images_HBOX->itemAt(i)->widget()->setVisible(allImageShowed);
    }
}

void ImageBox::loadPixmap(QString newImagePath)
{
    if(newImagePath=="") throw EMPTY_FILE_PATH;
    QPixmap newPixmap = QPixmap(newImagePath);
    ui->image->setPixmap(newPixmap);

    QFileInfo fileInfo(newImagePath);
    ui->ImageGroupBox->setTitle(fileInfo.fileName());

    updateImagePath(fileInfo.path());
}




void ImageBox::on_show_all_button_clicked()
{
    allImageShowed = !allImageShowed;
    updateStateImageAll();

}


void ImageBox::on_fullScreenButton_clicked()
{

}

