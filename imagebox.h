#ifndef IMAGEBOX_H
#define IMAGEBOX_H

#include <QWidget>

namespace Ui {
class ImageBox;
}

class ImageBox : public QWidget
{
    Q_OBJECT

public:
    explicit ImageBox(QWidget *parent = nullptr);
    ~ImageBox();

private:
    Ui::ImageBox *ui;

    QImage *image;
    QString imageName;


};

#endif // IMAGEBOX_H
