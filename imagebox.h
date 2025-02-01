#ifndef IMAGEBOX_H
#define IMAGEBOX_H

#define EMPTY_FILE_PATH -1
#define ERROR_FILE_LOAD -2


#include <QWidget>
#include <QLabel>
#include <QFileInfo>
#include <QList>
#include <QStringList>
#include <QDir>
#include <imagelistbutton.h>
namespace Ui {
class ImageBox;
}

class ImageBox : public QWidget
{
    Q_OBJECT

public:
    explicit ImageBox(QWidget *parent = nullptr);
    ImageBox(QString imagePath,QWidget *parent = nullptr);
    ~ImageBox();

private:
    Ui::ImageBox *ui;
    QString imagePath;
    QPixmap *pixmap;
    QList<QFileInfo> imageFilesInPath;

    bool allImageShowed = false;

    void updateImagePath(QString imagePath);
    void updateStateImageAll();



public:
    void loadPixmap(QString newImagePath);

private slots:
    void on_show_all_button_clicked();
    void on_fullScreenButton_clicked();
};

#endif // IMAGEBOX_H
