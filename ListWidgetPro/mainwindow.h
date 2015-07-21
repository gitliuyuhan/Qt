#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
class:MainWindow
主窗口类声明
by www.hnmade.com
 */
#include <QMainWindow>

class QListWidget;
class QListWidgetItem;
class QPaintEvent;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent (QPaintEvent * event);
private:
    void SetBgImage(const QString &strPath);
private slots:
    void Slot_ItemClicked(QListWidgetItem * item);
private:
    QListWidget *m_pListWidget;
    QString m_strPath;


};

#endif // MAINWINDOW_H
