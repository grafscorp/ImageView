#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    loadFileForm = new LoadFileForm(this);
    imagebox = new ImageBox(this);

    ui->VBox->addWidget(loadFileForm);
    ui->VBox->addWidget(imagebox);

    imagebox->setVisible(false);
    connect(ui->actionOpen_file,&QAction::triggered, this, &MainWindow::openFile);
    connect(loadFileForm, &LoadFileForm::clickedLoadButton, this, &MainWindow::openFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage(QString filePath)
{
    loadFileForm->setVisible(false);

    imagebox->loadPixmap(filePath);
    imagebox->setVisible(true);
}

void MainWindow::openFile()
{
    auto filePath = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Images (*.png *.jpg)"));
    loadImage(filePath);
}
