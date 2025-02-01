#ifndef IMAGELISTBUTTON_H
#define IMAGELISTBUTTON_H

#include <QWidget>

namespace Ui {
class ImageListButton;
}

class ImageListButton : public QWidget
{
    Q_OBJECT

public:
    explicit ImageListButton(QString imagePath,QWidget *parent = nullptr);
    ~ImageListButton();

private:
    Ui::ImageListButton *ui;
    QString imagePath;
signals:
    void clicked(QString);
private slots:
    void on_ImageButton_clicked();
};

#endif // IMAGELISTBUTTON_H
