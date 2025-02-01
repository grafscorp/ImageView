#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFile>
#include <QFileDialog>


#include <imagebox.h>
#include <loadfileform.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ImageBox* imagebox;
    LoadFileForm* loadFileForm;

    void loadImage(QString filePath);
private slots:
    void openFile();
};
#endif // MAINWINDOW_H
