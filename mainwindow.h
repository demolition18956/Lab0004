#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject* watched, QEvent* e);

private:
    Ui::MainWindow *ui;
    QLabel* statusLabel;

private slots:
    void ImportFile();
};

#endif // MAINWINDOW_H
