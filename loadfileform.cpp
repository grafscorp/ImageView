#include "loadfileform.h"
#include "ui_loadfileform.h"

LoadFileForm::LoadFileForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadFileForm)
{
    ui->setupUi(this);
}

LoadFileForm::~LoadFileForm()
{
    delete ui;
}

void LoadFileForm::on_loadButton_clicked()
{
    emit clickedLoadButton();
}
