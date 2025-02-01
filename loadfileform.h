#ifndef LOADFILEFORM_H
#define LOADFILEFORM_H

#include <QWidget>

namespace Ui {
class LoadFileForm;
}

class LoadFileForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoadFileForm(QWidget *parent = nullptr);
    ~LoadFileForm();

private:
    Ui::LoadFileForm *ui;
signals:
    void clickedLoadButton();
private slots:
    void on_loadButton_clicked();
};

#endif // LOADFILEFORM_H
