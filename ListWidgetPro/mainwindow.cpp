/*
class:MainWindow
��������ʵ��
by www.hnmade.com
 */
#include "mainwindow.h"
#include <QListWidget>

const int W_ICONSIZE = 96; //ͼƬ���
const int H_ICONSIZE = 96; //ͼƬ�߶�
const int H_ITEMSIZE = 110; //��Ԫ��߶�(��Ϊ��Ԫ��Ȱ���ͼƬ�ְ����ı�)

//���캯��
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    //����QListWidget����
    m_pListWidget = new QListWidget(this);
    //����QListWidget�еĵ�Ԫ���ͼƬ��С
    m_pListWidget->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
    m_pListWidget->setResizeMode(QListView::Adjust);
    //����QListWidget����ʾģʽ
    m_pListWidget->setViewMode(QListView::IconMode);
    //����QListWidget�еĵ�Ԫ��ɱ��϶�
    m_pListWidget->setMovement(QListView::Static);
    //����QListWidget�еĵ�Ԫ��ļ��
    m_pListWidget->setSpacing(10);

    //���δ���11����Ԫ��
    for(int nIndex = 0;nIndex<11;++nIndex)
    {
        //���ͼƬ·��
        QString strPath=QString(":/list/image/%1.jpg").arg(nIndex+1);
        //����ͼ��objPixmap
        QPixmap objPixmap(strPath);
        //����QListWidgetItem����(ע�⣺��Iconͼ�����������[96*96])---scaled����
        QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(W_ICONSIZE,H_ICONSIZE))),"animal tiger pig");
        //���õ�Ԫ��Ŀ�Ⱥ͸߶�
        pItem->setSizeHint(QSize(W_ICONSIZE,H_ITEMSIZE));
        m_pListWidget->insertItem(nIndex, pItem);

    }

    setCentralWidget(m_pListWidget);

    //�����źŲ�
    connect(m_pListWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(Slot_ItemClicked(QListWidgetItem*)));

    m_strPath = "";

    setWindowTitle("www.hnmade.com");
}

//���������ڱ���
void MainWindow::SetBgImage(const QString &strPath)
{
    QPixmap objPixmap(strPath);
    QPalette palette = this->palette();
    if(strPath.isEmpty())
    {
        palette.setBrush(QPalette::Base, QBrush(QColor(0,0,255)));
    }
    else
    {
        palette.setBrush(QPalette::Base, QBrush(objPixmap.scaled(width(),height())));
    }
    setPalette(palette);
}

//�ۺ���
void MainWindow::Slot_ItemClicked(QListWidgetItem * item)
{
    if(!item)
    {
        return;
    }
    int nRowIndex = m_pListWidget->row(item);

    m_strPath=QString(":/list/image/%1.jpg").arg(nRowIndex+1);
    update();
}
void MainWindow::paintEvent (QPaintEvent * event)
{
    SetBgImage(m_strPath);
}

//��������
MainWindow::~MainWindow()
{
}
