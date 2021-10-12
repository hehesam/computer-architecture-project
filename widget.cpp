#include "widget.h"
#include "ui_widget.h"
//#include"firstHeader.h"
#include<QTextEdit>
#include<QPushButton>
#include<QLabel>
#include<QDebug>
#include<QFileDialog>
#include<QMessageBox>
#include<iostream>



#include"run_all.h"
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_openFIleButtom_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                                                                        "/home",
                                                                                                          tr("Images (*.png *.xpm *.jpg *.mc)"));


    // change the QString to string
    string ss = fileName.toUtf8().constData();

    // Add double //
    int n = ss.length();
    for(int i=0;i<n;i++){
        string add = "//";
        if(ss[i]=='/'){
            ss.replace(i,1,add);
            i+=2;
        }
    }
    cout  << "string form " << ss << endl;

    char adrss[30] = {};

    n = ss.length();
    for(int i=0;i<n;i++)
        adrss[i] = ss[i];

    qDebug() <<"the char form "<< (char*)adrss ;


    take_input(adrss);

}

void Widget::on_startButtom_clicked()
{

    main();
}



void Widget::on_refreshButton_clicked()
{
    qDebug() << "working ";


    if(Lines[PC] && Lines[PC] != 234881024){


        process();

    }
   else{


        QMessageBox::information(this, "Message", "you have reached the end of program\n the PC is ");
//        qDebug() << "this is the end of the program";

    }

    extern int R[16] ;
    extern int Lines[100];
    extern int PC;
    extern int instructionCounter;
    extern int R_usage[16];
    extern int instructionCounter ;

//    if (instructionCounter > 100){
//        QMessageBox::warning(this, "Error", "your program is probebly in a infinite loop");

//    }

    int sum = 0;
    for(int i=0;i<16;i++)
        sum+=R_usage[i];

    qDebug() << "this is sum "<<sum;





    int RR[16];

    if(sum){
    for(int i=0;i<16;i++){
        RR[i] = (R_usage[i]*100/sum);


        qDebug() << "R_usage["<<i<<"] : " << R_usage[i];
        qDebug() << "RR["<<i<<"] : " << RR[i];
        }
    }






    QString words[16];
    for(int i=0;i<16;i++){
        words[i] = "the value of register[" + QString::number(i) + "] is :  " + QString::number(R[i]) + "\n" + "Percentage of use : " + QString::number(RR[i]) + "%";
    }





    ui->textEditRegister1->setText(words[1]);
    ui->textEditRegister2->setText(words[2]);
    ui->textEditRegister3->setText(words[3]);
    ui->textEditRegister4->setText(words[4]);
    ui->textEditRegister5->setText(words[5]);
    ui->textEditRegister6->setText(words[6]);
    ui->textEditRegister7->setText(words[7]);
    ui->textEditRegister8->setText(words[8]);
    ui->textEditRegister9->setText(words[9]);
    ui->textEditRegister10->setText(words[10]);
    ui->textEditRegister11->setText(words[11]);
    ui->textEditRegister12->setText(words[12]);
    ui->textEditRegister13->setText(words[13]);
    ui->textEditRegister14->setText(words[14]);
    ui->textEditRegister15->setText(words[15]);

    ui->pcLCD->display(PC);
    ui->intructionCounter->display(instructionCounter);



}
