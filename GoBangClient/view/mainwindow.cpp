#include "view/mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QColor btnColor = QColor(0,161,241);

    QPalette btnPalette = QPalette(btnColor);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(124,187,0));
    this->setPalette(palette);
    ui->setupUi(this);

    //connect();

}

MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::closeEvent( QCloseEvent  *event )//关闭窗口会先处理该事件函数
{
    switch( QMessageBox::critical( this, "警告",
                                      "确定要退出RicardoGoBang吗？",
                                      "是", "否",
                                      0, 1 ) )
    {
    case 0:
        event->accept();
        break;
    case 1:
    default:
        event->ignore();
        break;
    }
}

void MainWindow::reshow(){
    this->show();
}


void MainWindow::on_btnPVP_clicked()
{
    this->hide();
    ConnectDig *connectDig=new ConnectDig();
    connectDig->show();
    connect(connectDig,&ConnectDig::backhome,this,&MainWindow::reshow);
}

void MainWindow::on_btnPVM_clicked()
{
    PVMWindow *pvmwindow = new PVMWindow(this);
    pvmwindow->show();
    connect(pvmwindow,SIGNAL(sendsignal()),this,SLOT(reshow()));
    this->hide();
}

void MainWindow::on_btnQuit_clicked()
{
    exit(0);
}
