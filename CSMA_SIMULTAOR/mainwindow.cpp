#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iomanip>
#include<vector>
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<deque>
#include<qstring.h>
//***** ADD DISPLAY OF DATA AT LINE 383
using namespace std;
vector<int> setFrame(vector<int> data, int rec); //rec=decimal value
int decode(vector<int> frame, int rec);
float getRandom();

int transmission_line[25];
int arrayA[25];
int arrayB[25];
int arrayC[25];
int arrayD[25];
int arrayE[25];
int arrayF[25];

int index_A=0;
int index_B=4;
int index_C=9;
int index_D=14;
int index_E=18;
int index_F=24;

int flagA=0;
int flagB=0;
int flagC=0;
int flagD=0;
int flagE=0;
int flagF=0;

int xsender;
int xreceiver;
std::vector<int> xdata;
int input_switch=0;


int k[6];
int wait_persistance[6];

std::vector<int> send_stack[6];
deque<int> read_queue[6];
vector<int> send_frame[6];       // To store the frame so that we can send after the jamming
//vector<int> read_stack[6];    // NOT NEEDED ANYMORE

                                    //LET 1 TIME SLOT BE 1 SECOND ( TIME SLOTS ARE USER CONTROLLED BUT IF AUTOMATED , WE CAN RUN IT FOR A SPECIFIC TIME PERIOD )
int status[6]={0,0,0,0,0,0};        //listen=0   read=1   send= 2   jam=3     send_wait=4

void next_step();
int switchRec;
vector<int> recData;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        for(int i=0;i<25;i++)           //initialising the node arrays
            arrayA[i]=0;

        for(int i=0;i<25;i++)
            arrayB[i]=0;

        for(int i=0;i<25;i++)
            arrayC[i]=0;

        for(int i=0;i<25;i++)
            arrayD[i]=0;

        for(int i=0;i<25;i++)
            arrayE[i]=0;

        for(int i=0;i<25;i++)
            arrayF[i]=0;



        for(int i=0;i<25;i++)
            transmission_line[i]=0;

        for(int i=0;i<6;i++)
            k[i]=0;

        for(int i=0;i<6;i++)
            wait_persistance[i]=0;

        ui->comboBox->addItem("A");             //adding items to the dropdown menu
        ui->comboBox->addItem("B");
        ui->comboBox->addItem("C");
        ui->comboBox->addItem("D");
        ui->comboBox->addItem("E");
        ui->comboBox->addItem("F");

        ui->comboBox_2->addItem("A");
        ui->comboBox_2->addItem("B");
        ui->comboBox_2->addItem("C");
        ui->comboBox_2->addItem("D");
        ui->comboBox_2->addItem("E");
        ui->comboBox_2->addItem("F");


        next_step();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->receiverData->clear();
    xsender=ui->comboBox_2->currentIndex();
    xreceiver=ui->comboBox->currentIndex();
    int temp=ui->textEdit_26->toPlainText().toInt();    //check here
    QString str=ui->textEdit_26->toPlainText();
    int temp_inverted;
    while(temp!=0)                                      //inverting the input
        {
            temp_inverted=temp%10;
            temp_inverted=temp_inverted*10;
            temp=temp/10;
        }
    while(temp_inverted!=0)                             //bit by bit pushing into the vector
        {
            xdata.push_back(temp_inverted%10);
            temp_inverted=temp_inverted/10;
        }
    input_switch=1;
    next_step();
    ui->textEdit_25->setPlainText(QString::number(transmission_line[0]));
    ui->textEdit_24->setPlainText(QString::number(transmission_line[1]));
    ui->textEdit_23->setPlainText(QString::number(transmission_line[2]));
    ui->textEdit_22->setPlainText(QString::number(transmission_line[3]));
    ui->textEdit_21->setPlainText(QString::number(transmission_line[4]));
    ui->textEdit_20->setPlainText(QString::number(transmission_line[5]));
    ui->textEdit_19->setPlainText(QString::number(transmission_line[6]));
    ui->textEdit_18->setPlainText(QString::number(transmission_line[7]));
    ui->textEdit_17->setPlainText(QString::number(transmission_line[8]));
    ui->textEdit_16->setPlainText(QString::number(transmission_line[9]));
    ui->textEdit_15->setPlainText(QString::number(transmission_line[10]));
    ui->textEdit_14->setPlainText(QString::number(transmission_line[11]));
    ui->textEdit_13->setPlainText(QString::number(transmission_line[12]));
    ui->textEdit_12->setPlainText(QString::number(transmission_line[13]));
    ui->textEdit_11->setPlainText(QString::number(transmission_line[14]));
    ui->textEdit_10->setPlainText(QString::number(transmission_line[15]));
    ui->textEdit_9->setPlainText(QString::number(transmission_line[16]));
    ui->textEdit_8->setPlainText(QString::number(transmission_line[17]));
    ui->textEdit_7->setPlainText(QString::number(transmission_line[18]));
    ui->textEdit_6->setPlainText(QString::number(transmission_line[19]));
    ui->textEdit_5->setPlainText(QString::number(transmission_line[20]));
    ui->textEdit_4->setPlainText(QString::number(transmission_line[21]));
    ui->textEdit_3->setPlainText(QString::number(transmission_line[22]));
    ui->textEdit_2->setPlainText(QString::number(transmission_line[23]));
    ui->textEdit->setPlainText(QString::number(transmission_line[24]));
    ui->senderData->setPlainText(str);
}

void MainWindow::on_pushButton_2_clicked()
{
    next_step();
    ui->textEdit_25->setPlainText(QString::number(transmission_line[0]));
    ui->textEdit_24->setPlainText(QString::number(transmission_line[1]));
    ui->textEdit_23->setPlainText(QString::number(transmission_line[2]));
    ui->textEdit_22->setPlainText(QString::number(transmission_line[3]));
    ui->textEdit_21->setPlainText(QString::number(transmission_line[4]));
    ui->textEdit_20->setPlainText(QString::number(transmission_line[5]));
    ui->textEdit_19->setPlainText(QString::number(transmission_line[6]));
    ui->textEdit_18->setPlainText(QString::number(transmission_line[7]));
    ui->textEdit_17->setPlainText(QString::number(transmission_line[8]));
    ui->textEdit_16->setPlainText(QString::number(transmission_line[9]));
    ui->textEdit_15->setPlainText(QString::number(transmission_line[10]));
    ui->textEdit_14->setPlainText(QString::number(transmission_line[11]));
    ui->textEdit_13->setPlainText(QString::number(transmission_line[12]));
    ui->textEdit_12->setPlainText(QString::number(transmission_line[13]));
    ui->textEdit_11->setPlainText(QString::number(transmission_line[14]));
    ui->textEdit_10->setPlainText(QString::number(transmission_line[15]));
    ui->textEdit_9->setPlainText(QString::number(transmission_line[16]));
    ui->textEdit_8->setPlainText(QString::number(transmission_line[17]));
    ui->textEdit_7->setPlainText(QString::number(transmission_line[18]));
    ui->textEdit_6->setPlainText(QString::number(transmission_line[19]));
    ui->textEdit_5->setPlainText(QString::number(transmission_line[20]));
    ui->textEdit_4->setPlainText(QString::number(transmission_line[21]));
    ui->textEdit_3->setPlainText(QString::number(transmission_line[22]));
    ui->textEdit_2->setPlainText(QString::number(transmission_line[23]));
    ui->textEdit->setPlainText(QString::number(transmission_line[24]));
    if(switchRec==1)
    {
        QString tmp("");
        for(int i=0;i<recData.size();i++)
        {    tmp.append(QString::number(recData[i]));
                cout<<recData[i];
        }
        ui->receiverData->setPlainText(tmp);
        switchRec=0;
    }
}












////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////P PERSISTENCE AND BACKOFF/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

void backoff(int index)
{

        if(k[index]==5)
            {
                send_stack[index].clear();
                status[index]=0;
            }
        k[index]++;
        int R=(pow(2.0,k[index]))-1;
        wait_persistance[index]= rand()%(R+ 1);

}

float getrandom()           //GENERATES A RANDOM N.O. B/W 0->1
{
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

void p_persistence(int index)
{
    if(wait_persistance[index]==0)
    {
        float P=0.20;              // Akhil- As 0.015  is such a small number. The nodes will never send the data. I am assuming 20% as the prob (AAHANS -Probability that only node n will send is 1/(2^6))
        if(transmission_line[index]==0) //If line not idle goto backoff
        {
            float R=getrandom();
            if(R<=P)
            {
                status[index]=2;
                k[index]=0;
            }
            else if(transmission_line[index]!=0)
                    backoff(index);
        }
    }
    else
    {
        wait_persistance[index]--;                        //assuming each timeslot to be 20 bits
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////FRAME ENCODE/DECODE/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  NODE ADDRESS
 * A-000
 * B-001
 * C-010
 * D-011
 * E-100
 * F-101
  */
vector<int> setFrame(vector<int> data,int rec) //rec=decimal value
{
    vector<int> frame;
    //adding flag 01111110
    frame.push_back(0);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(0);
    int count=0;
    //adding receiver address

    switch(rec)
    {
        case 0:
            frame.push_back(0);
            frame.push_back(0);
            frame.push_back(0);
            break;
        case 1:
            frame.push_back(0);
            frame.push_back(0);
            frame.push_back(1);
            break;
        case 2:
            frame.push_back(0);
            frame.push_back(1);
            frame.push_back(0);
            break;
        case 3:
            frame.push_back(0);
            frame.push_back(1);
            frame.push_back(1);
            break;
        case 4:
            frame.push_back(1);
            frame.push_back(0);
            frame.push_back(0);
            break;
        case 5:
            frame.push_back(1);
            frame.push_back(0);
            frame.push_back(1);
            break;
    }

    //adding data
    for(int i=0;i<data.size();i++)
    {
        int x=data[i];
        if(x==1)
            count++;
        else
            count=0;
        frame.push_back(x);
        if(count==5)
        {
            frame.push_back(0);
            count=0;
        }
    }

    //adding flag 01111110
    frame.push_back(0);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(0);
    vector<int> copy;
    //reversing the frame
    for(int i=frame.size()-1;i>=0;i--)
    {
        int x=frame[i];
        copy.push_back(x);
    }

    return copy;
      //return frame;
}
// ABDUL : changing the return type of decode to void and printing inside the function only.
// I will be sending the frame received to this decode function and then
// let it decode and print. If the receiver code does not match
// there will be no return /display. It will just ignore the message .
void decode(deque<int> frame, int rec)
{
    vector<int> data;
    int len=frame.size();
    int cmp=0;
    for(int i=8;i<=10;i++)//cmp stores address of intended receiver
    {
        cmp*=10;
        cmp+=frame[i];
    }
    //cmp is in binary form
    int dec=0;
    int c=0;
    while(cmp!=0)//calculating the decimal equivalent of address stored in cmp
    {
        int d=cmp%10;
        dec+=d*pow(2.0,c);
        c++;
        cmp/=10;
    }
    //dec represent decimal form of cmp
    if(rec==dec)//if  "this" node is the receiver the display the data received.
    {
        for(int i=11;i<=frame.size()-9;i++)
          data.push_back(frame[i]);
        recData=data;
        switchRec=1;
    }



}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


void next_step()
{
        int x=1;        //del

//-----------------------------------------------------------------------------------------------
            if(input_switch==1)                            //taking in the data
            {
                vector<int> xframe;
                if(xsender==xreceiver)
                {
                    //cout<<endl<<"STATION CANNOT SEND A MESSAGE TO ITSELF !!! " <<endl;
                    goto haha;
                }
                xframe=setFrame(xdata,xreceiver);


                send_frame[xsender]=xframe;              //storing the frame before sending

                status[xsender]=4;                      // setting the status of the sender station to wait state ( before send state)
                send_stack[xsender]=xframe;

                input_switch=0;
            }
            haha:
//-----------------------------------------------------------------------------------------------
                                                                //P persistant
            for(int i=0;i<6;i++)
                {
                    if(status[i]==4)
                        {   p_persistence(i);
                        }
                }
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
                                            //updating the linear arrays of each node

                                            //shift  A

            for(int i=24;i>index_A;i--)
                arrayA[i]=arrayA[i-1];
            arrayA[index_A]=0;

            for(int i=0;i<index_B;i++)      //shift  B
                arrayB[i]=arrayB[i+1];
            for(int i=24;i>index_B;i--)
                arrayB[i]=arrayB[i-1];
            arrayB[index_B]=0;


            for(int i=0;i<index_C;i++)      //shift  C
                arrayC[i]=arrayC[i+1];
            for(int i=24;i>index_C;i--)
                arrayC[i]=arrayC[i-1];
            arrayC[index_C]=0;

            for(int i=0;i<index_D;i++)      //shift  D
                arrayD[i]=arrayD[i+1];
            for(int i=24;i>index_D;i--)
                arrayD[i]=arrayD[i-1];
            arrayD[index_D]=0;

            for(int i=0;i<index_E;i++)      //shift  E
                arrayE[i]=arrayE[i+1];
            for(int i=24;i>index_E;i--)
                arrayE[i]=arrayE[i-1];
            arrayE[index_E]=0;

            for(int i=0;i<index_F;i++)      //shift  F
                arrayF[i]=arrayF[i+1];
            arrayF[index_F]=0;


            if(status[0]==2)                                //pushing send stack or 0 [2:send mode] [Node 0]
                {   if(send_stack[0].empty())
                       status[0]=0;
                    else
                    {
                        int y=send_stack[0][send_stack[0].size()-1];
                            arrayA[index_A]=y;
                            send_stack[0].pop_back();

                    }


                }
            else
                arrayA[index_A]=0;


            if(status[1]==2)                                 //pushing send stack or 0 [node 1]
                {
                    if(send_stack[1].empty())
                       status[1]=0;
                    else
                    {
                    int y=send_stack[1][send_stack[1].size()-1];
                    send_stack[1].pop_back();
                    arrayB[index_B]=y;
                    }
                }
            else
                arrayB[index_B]=0;

            if(status[2]==2)                                    //pushing send stack or 0
                {
                    if(send_stack[2].empty())
                       status[2]=0;
                    else
                    {
                    int y=send_stack[2][send_stack[2].size()-1];
                    send_stack[2].pop_back();
                    arrayC[index_C]=y;
                    }
                }
            else
                arrayC[index_C]=0;

            if(status[3]==2)                                                        //pushing send stack or 0
                {   if(send_stack[3].empty())
                       status[3]=0;
                    else
                    {
                    int y=send_stack[3][send_stack[3].size()-1];
                    send_stack[3].pop_back();
                    arrayD[index_D]=y;
                }
                }
            else
                arrayD[index_D]=0;

            if(status[4]==2)                                                    //pushing send stack or 0
                {   if(send_stack[4].empty())
                       status[4]=0;
                    else
                    {
                    int y=send_stack[4][send_stack[4].size()-1];
                    send_stack[4].pop_back();
                    arrayE[index_E]=y;
                    }
                }
            else
                arrayE[index_E]=0;

            if(status[5]==2)                                                    //pushing send stack or 0
                {   if(send_stack[5].empty())
                       status[5]=0;
                    else
                    {
                    int y=send_stack[5][send_stack[5].size()-1];
                    send_stack[5].pop_back();
                    arrayF[index_F]=y;
                    }
                }
            else
                arrayF[index_F]=0;
//-----------------------------------------------------------------------------------------------
                                            //addition of the node arrays

            for(int i=0;i<25;i++)
                {
                    transmission_line[i]=arrayA[i]+arrayB[i]+arrayC[i]+arrayD[i]+arrayE[i]+arrayF[i];
                }
//----------------------------------------------------------------------------------------------

//************************************************************************************************

      /*      //cout<<endl<<"\nTransmission line -----> ";
            for(j=0;j<25;j++)
            {
                cout<<setw(5)<<transmission_line[j];

            }
        */


//************************************************************************************************

    // checking if the index position in transmission line for each node is >1 , setting its status to JAM
if(transmission_line[index_A]>1)
    { status[0]=3;
        flagA=5;
    }
if(transmission_line[index_B]>1)
    {
        status[1]=3;
        flagB=5;
    }
if(transmission_line[index_C]>1)
    {
        status[2]=3;
        flagC=5;
    }
if(transmission_line[index_D]>1)
    {
        status[3]=3;
        flagD=5;
    }
if(transmission_line[index_E]>1)
    {
        status[4]=3;
        flagE=5;
    }
if(transmission_line[index_F]>1)
    {
        status[5]=3;
        flagF=5;
    }
//----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
                                                                        //IF jamming signal is detected - go to back off

    if(status[0]==2|| status[0]==1)
        {
            if(transmission_line[index_A]<0)
                {   backoff(0);
                    send_stack[0].clear();
                    read_queue[0].clear();
                    send_stack[0]=send_frame[0];
                    status[0]=4;

                }
        }

    if(status[1]==2|| status[1]==1)
        {
            if(transmission_line[index_B]<0)
                {   backoff(1);
                    send_stack[1].clear();
                    read_queue[1].clear();
                    send_stack[1]=send_frame[1];
                    status[1]=4;

                }
        }
    if(status[2]==2|| status[2]==1)
        {
            if(transmission_line[index_C]<0)
                {   backoff(2);
                    send_stack[2].clear();
                    read_queue[2].clear();
                    send_stack[2]=send_frame[2];
                    status[2]=4;

                }
        }
    if(status[3]==2|| status[3]==1)
        {
            if(transmission_line[index_D]<0)
                {   backoff(3);
                    send_stack[3].clear();
                    read_queue[3].clear();
                    send_stack[3]=send_frame[3];
                    status[3]=4;

                }
        }
      if(status[4]==2|| status[4]==1)
        {
            if(transmission_line[index_E]<0)
                {   backoff(4);
                    send_stack[4].clear();
                    read_queue[4].clear();
                    send_stack[4]=send_frame[4];
                    status[4]=4;

                }
        }
     if(status[5]==2|| status[5]==1)
        {
            if(transmission_line[index_F]<0)
                {   backoff(5);
                    send_stack[5].clear();
                    read_queue[5].clear();
                    send_stack[5]=send_frame[5];
                    status[5]=4;

                }
        }
//-----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
                                        //updating the node arrays with abnormal transmission line signals

            for (int i = 0; i < 25; ++i)
            {
            if(transmission_line[i]>1)
                {if((status[0]==2) &&(arrayA[i]>=1))
                    arrayA[i]=2;

                if((status[1]==2) &&(arrayB[i]>=1))
                    arrayB[i]=2;

                if((status[2]==2) &&(arrayC[i]>=1))
                    arrayC[i]=2;

                if((status[3]==2) &&(arrayD[i]>=1))
                    arrayD[i]=2;

                if((status[4]==2) &&(arrayE[i]>=1))
                    arrayE[i]=2;

                if((status[5]==2) &&(arrayF[i]>=1))
                    arrayF[i]=2;
                }



            }


            // if any node (A-F) is jammed , pushing 5 bits of --99 on either side , clearing send stack and read queue of them , and
            // checking the  status of A and B -- delete this later :
           // cout<<endl<<endl;
           //     cout<<endl<<"The statuses of stations A B C D E F are  : "<<status[0]<<"   "<<status[1]<<"   "<<status[2]<<"   "<<status[3]<<"   " <<status[4]<<"   "<<status[5]<<endl;
           // cout<<endl<<endl;
            if(status[0]==3)
            {
                    send_stack[0].clear();
                    if(flagA!=0)
                        {  arrayA[index_A]=-99;
                            flagA--;
                        }
                    else
                    {
                        backoff(0);
                        send_stack[0]=send_frame[0];
                        status[0]=4;
                    }
            }
            if(status[1]==3)
            {
                    send_stack[1].clear();
                    if(flagB!=0)
                        {  arrayB[index_B]=-99;
                            flagB--;
                        }
                    else
                    {   backoff(1);
                        send_stack[1]=send_frame[1];
                        status[1]=4;
                    }
            }
            if(status[2]==3)
            {
                    send_stack[2].clear();
                    if(flagC!=0)
                        {  arrayC[index_C]=-99;
                            flagC--;
                        }
                    else
                    {   backoff(2);
                        send_stack[2]=send_frame[2];
                        status[2]=4;
                    }
            }
            if(status[3]==3)
            {
                    send_stack[3].clear();
                    if(flagD!=0)
                        {  arrayD[index_D]=-99;
                            flagD--;
                        }
                    else
                    {   backoff(3);
                        send_stack[3]=send_frame[3];
                        status[3]=4;
                    }
            }
            if(status[4]==3)
            {
                    send_stack[4].clear();
                    if(flagE!=0)
                        {  arrayE[index_E]=-99;
                            flagE--;
                        }
                    else
                    {   backoff(4);
                        send_stack[4]=send_frame[4];
                        status[4]=4;
                    }
            }
            if(status[5]==3)
            {
                    send_stack[5].clear();
                    if(flagF!=0)
                        {  arrayF[index_F]=-99;
                            flagF--;
                        }
                    else
                    {   backoff(5);
                        send_stack[5]=send_frame[5];
                        status[5]=4;
                    }
            }



//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
                                                                //updating the read stack
            if(status[0]==0 || status[0]==1)
                read_queue[0].push_back(transmission_line[index_A]);
            if(status[1]==0 || status[1]==1)
                read_queue[1].push_back(transmission_line[index_B]);
            if(status[2]==0 || status[2]==1)
                read_queue[2].push_back(transmission_line[index_C]);
            if(status[3]==0 || status[3]==1)
                read_queue[3].push_back(transmission_line[index_D]);
            if(status[4]==0 || status[4]==1)
                read_queue[4].push_back(transmission_line[index_E]);
            if(status[5]==0 || status[5]==1)
                read_queue[5].push_back(transmission_line[index_F]);

//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
                            //CLEARING THE READSTACK IF IT HAS SIZE >8 and has no 111111
                            //ELSE SETTING MODE TO READ
            if((read_queue[0].size()==8)&&(status[0]==0))
                {   int i;
                    for( i=1;i<7;i++)
                    {   if(read_queue[0][i]!=1)
                            {read_queue[0].pop_front();
                              break;
                            }
                    }
                    if(i==7)
                     status[0]=1;

                }
            if((read_queue[1].size()==8)&&(status[1]==0))
                {   int i;
                    for( i=1;i<7;i++)
                    {   if(read_queue[1][i]!=1)
                            {read_queue[1].pop_front();
                              break;
                            }
                    }
                    if(i==7)
                     status[1]=1;
                }
            if((read_queue[2].size()==8)&&(status[2]==0))
                {int i;
                    for( i=1;i<7;i++)
                    {   if(read_queue[2][i]!=1)
                            {read_queue[2].pop_front();
                             break;
                            }
                    }
                    if(i==7)
                     status[2]=1;

                }
            if((read_queue[3].size()==8)&&(status[3]==0))
                {int i;
                    for( i=1;i<7;i++)
                    {   if(read_queue[3][i]!=1)
                            {read_queue[3].pop_front();
                             break;
                            }
                    }
                    if(i==7)
                     status[3]=1;

                }
            if((read_queue[4].size()==8)&&(status[4]==0))
                {int i;
                    for( i=1;i<7;i++)
                    {   if(read_queue[4][i]!=1)
                            {read_queue[4].pop_front();
                             break;
                            }
                    }
                    if(i==7)
                     status[4]=1;

                }
            if((read_queue[5].size()==8)&&(status[5]==0))
                {int i;
                    for( i=1;i<7;i++)
                    {   if(read_queue[5][i]!=1)
                            {read_queue[5].pop_front();
                             break;
                            }
                    }
                    if(i==7)
                     status[5]=1;

                }
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
                                            //in read mode read till you get the last few bits as 1111110
                                            //if so decode
                                            // calling the decode function from here once it establishes the
                                            // starting part of the message ( 01111110)


            if(status[0]==1 && read_queue[0].size()>9)
                {   int i;
                    for( i=read_queue[0].size()-2;i>read_queue[0].size()-8;i--)
                    {
                        if(read_queue[0][i]!=1)
                                break;
                    }
                    if(i==read_queue[0].size()-8)
                        {//cout<<endl<<endl<<"FRAME RECIEVED AT 0"<<endl;
                         //calling the decode function here , sending the read queue and the receivers number

                         decode(read_queue[0],0);

                         while(read_queue[0].size())
                            read_queue[0].pop_front();
                         status[0]=0;
                        }
                }


            if(status[1]==1 && read_queue[1].size()>9)
                {   int i;
                    for( i=read_queue[1].size()-2;i>read_queue[1].size()-8;i--)
                    {
                        if(read_queue[1][i]!=1)
                                break;
                    }
                    if(i==read_queue[1].size()-8)
                        {//cout<<endl<<endl<<"FRAME RECIEVED AT 1"<<endl;

                        decode(read_queue[1],1);

                         while(read_queue[1].size())
                            read_queue[1].pop_front();
                        status[1]=0;
                        }
                }

            if(status[2]==1 && read_queue[2].size()>9)
                {   int i;
                    for( i=read_queue[2].size()-2;i>read_queue[2].size()-8;i--)
                    {
                        if(read_queue[2][i]!=1)
                                break;
                    }
                    if(i==read_queue[2].size()-8)
                        {//cout<<endl<<endl<<"FRAME RECIEVED AT 2"<<endl;

                            decode(read_queue[2],2);

                         while(read_queue[2].size())
                            read_queue[2].pop_front();
                        status[2]=0;
                        }
                }

            if(status[3]==1 && read_queue[3].size()>9)
                {   int i;
                    for( i=read_queue[3].size()-2;i>read_queue[3].size()-8;i--)
                    {
                        if(read_queue[3][i]!=1)
                                break;
                    }
                    if(i==read_queue[3].size()-8)
                        {//cout<<endl<<endl<<"FRAME RECIEVED AT 3"<<endl;

                            decode(read_queue[3],3);

                         while(read_queue[3].size())
                            read_queue[3].pop_front();
                         status[3]=0;
                        }
                }

            if(status[4]==1 && read_queue[4].size()>9)
                {   int i;
                    for( i=read_queue[4].size()-2;i>read_queue[4].size()-8;i--)
                    {
                        if(read_queue[4][i]!=1)
                                break;
                    }
                    if(i==read_queue[4].size()-8)
                        {//cout<<endl<<endl<<"FRAME RECIEVED AT 4"<<endl;

                            decode(read_queue[4],4);

                         while(read_queue[4].size())
                            read_queue[4].pop_front();
                         status[4]=0;
                        }
                }

            if(status[5]==1 && read_queue[5].size()>9)
                {   int i;
                    for( i=read_queue[5].size()-2;i>read_queue[5].size()-8;i--)
                    {
                        if(read_queue[5][i]!=1)
                                break;
                    }
                    if(i==read_queue[5].size()-8)
                        {//cout<<endl<<endl<<"FRAME RECIEVED AT 5"<<endl;

                        decode(read_queue[5],5);

                         while(read_queue[5].size())
                            read_queue[5].pop_front();
                         status[5]=0;
                        }
                }
//----------------------------------------------------------------------------------------------------



           // cout<<endl<<endl;
           // cout<<"GO TO NEXT STEP ? ( 1 for yes , 0 for no to exit the program ) : ";        //next step
           // cin>>x;



}


