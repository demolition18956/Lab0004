#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QFile>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusLabel = new QLabel("0",this);
    statusBar()->addWidget(statusLabel);

    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::ImportFile);

    this->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ImportFile(){
    qDebug() << ui->lineEdit->text();

    QFile inFile(ui->lineEdit->text());
    if (!inFile.exists()){
        qDebug() << "Error -- File does not exist";
    } else if (!inFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "oop. try again later";
    }
    else {
        qDebug() << "File opened for input";

        QTextStream inStream(&inFile);

        while(!inStream.atEnd()){
            QString s = inStream.readLine();
            ui->comboBox->addItem(s);
            qDebug() << s;
        }
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent* ke = static_cast<QKeyEvent*>(e);
        if (ke->key() == Qt::Key_Escape){
            qDebug() << "Escape";
            bool ok;
            int n = statusLabel->text().toInt(&ok) + 1;
            if (ok){
                statusLabel->setText(QString::number(n));
            }
            return true;
        }
    }
    return QMainWindow::eventFilter(watched,e);
}
