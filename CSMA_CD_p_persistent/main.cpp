#include"mainwindow.h"
#include <QApplication>
#include<vector>
#include<iostream>
#include<cmath>
#include<random>
#include<deque>
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

std::vector<int> send_stack[6];
deque<int> read_queue[6];
                                    //LET 1 TIME SLOT BE 1 SECOND
int status[6]={0,0,0,0,0,0};		//listen=0   read=1   send= 2   jam=3
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////P PERSISTENCE AND BACKOFF/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
void backoff()
{
    //backoff algo
}
float getRandom()           //GENERATES A RANDOM N.O. B/W 0->1
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    return dis(gen);
}
void sleep(long d)              //causes a time delay
{
    clock_t start=clock();
    while(clock() - start < d); //loop until time's up
}
void p_persistence(int index)
{
    float P=0.015625;               //Probability that only node n will send is 1/(2^6)
    if(transmission_line[index]!=0) //If line not idle goto backoff
        backoff();
    else
    {
        repeat:
        float R=getRandom();
        if(R<=P)
        {
            //send message
        }
        else
        {
            sleep(1000000);         //wait for 1 time slot
            if(transmission_line[index]!=0)
                backoff();
            goto repeat;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////FRAME ENCODE/DECODE/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
/*	NODE ADDRESS
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
    cout<<"\n";
    return copy;
      //return frame;
}

int decode(vector<int> frame, int rec)
{
    int len=frame.size();
    int cmp=0;
    for(int i=8;i<=10;i++)
    {
        cmp*=10;
        cmp+=frame[i];
    }
    cout<<cmp<<"\n";

    for(int i=11;i<=frame.size()-9;i++)
        cout<<frame[i];
    cout<<"\n";
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


void next_step()
{
        int x=1;		//del


        while(x!=0)
        {
            cout<<"Do you want to send message(0/1)";
            cin>>x;

//-----------------------------------------------------------------------------------------------
            if(x==1)							//taking in the data
            {	vector<int> xframe;
                int xsender;
                int xreceiver;

                std::vector<int> xdata;


                cout<<"\nEnter the sender-";
                cin>>xsender;
                cout<<"\nEnter the receiver-";
                cin>>xreceiver;
                cout<<"\nEnter data(-1 to stop)-";
                int y;
                cin>>y;
                do{	xdata.push_back(y);
                    cin>>y;
                }while(y!=-1);

                xframe=setFrame(xdata,xreceiver);
                //frame(xdata,xreceiver)
                                    //del
                //int arr[4]={2,0,1,1};
                //for(int i=0;i<4;i++)
                //	xframe.push_back(arr[i]);
                cout<<"\nThe frame to be sent:";
                for(int i=0;i<xframe.size();i++)
                    cout<<xframe[i];

                status[xsender]=2;
                send_stack[xsender]=xframe;

                cout<<"\nsendstack";
                for(int i=0;i<send_stack[xsender].size();i++)
                    cout<<send_stack[xsender][i];


            }
//-----------------------------------------------------------------------------------------------
                                            //updating the linear arrays of each node

                                            //shift  A

            for(int i=24;i>index_A;i--)
                arrayA[i]=arrayA[i-1];
            arrayA[index_A]=0;

            for(int i=0;i<index_B;i++)		//shift  B
                arrayB[i]=arrayB[i+1];
            for(int i=24;i>index_B;i--)
                arrayB[i]=arrayB[i-1];
            arrayB[index_B]=0;


            for(int i=0;i<index_C;i++)		//shift  C
                arrayC[i]=arrayC[i+1];
            for(int i=24;i>index_C;i--)
                arrayC[i]=arrayC[i-1];
            arrayC[index_C]=0;

            for(int i=0;i<index_D;i++)		//shift  D
                arrayD[i]=arrayD[i+1];
            for(int i=24;i>index_D;i--)
                arrayD[i]=arrayD[i-1];
            arrayD[index_D]=0;

            for(int i=0;i<index_E;i++)		//shift  E
                arrayE[i]=arrayE[i+1];
            for(int i=24;i>index_E;i--)
                arrayE[i]=arrayE[i-1];
            arrayE[index_E]=0;

            for(int i=0;i<index_F;i++)		//shift  F
                arrayF[i]=arrayF[i+1];
            arrayF[index_F]=0;


            if(status[0]==2)										//pushing send stack or 0
                {	if(send_stack[0].empty())
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


            if(status[1]==2)									//pushing send stack or 0
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

            if(status[2]==2)											//pushing send stack or 0
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

            if(status[3]==2)														//pushing send stack or 0
                {	if(send_stack[3].empty())
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

            if(status[4]==2)													//pushing send stack or 0
                {	if(send_stack[4].empty())
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

            if(status[5]==2)													//pushing send stack or 0
                {	if(send_stack[5].empty())
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
                                                                                //Displaying the node arrays and transmission line
            int j;
            cout<<"\narray A printing";
            for(j=0;j<25;j++)
            {
                cout<<arrayA[j];

            }

            cout<<"\narray B printing";
            for(j=0;j<25;j++)
            {
                cout<<arrayB[j];

            }

            cout<<"\narray C printing";
            for(j=0;j<25;j++)
            {
                cout<<arrayC[j];

            }

            cout<<"\narray D printing";
            for(j=0;j<25;j++)
            {
                cout<<arrayD[j];

            }

            cout<<"\narray E printing";
            for(j=0;j<25;j++)
            {
                cout<<arrayE[j];

            }

            cout<<"\narray F printing";
            for(j=0;j<25;j++)
            {
                cout<<arrayF[j];

            }

            cout<<"\nTrans line     -";
            for(j=0;j<25;j++)
            {
                cout<<transmission_line[j];

            }


//************************************************************************************************

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
                {	int i;
                    for( i=1;i<7;i++)
                    {	if(read_queue[0][i]!=1)
                            {read_queue[0].pop_front();
                              break;
                            }
                    }
                    if(i==7)
                     status[0]=1;

                }
            if((read_queue[1].size()==8)&&(status[1]==0))
                {	int i;
                    for( i=1;i<7;i++)
                    {	if(read_queue[1][i]!=1)
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
                    {	if(read_queue[2][i]!=1)
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
                    {	if(read_queue[3][i]!=1)
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
                    {	if(read_queue[4][i]!=1)
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
                    {	if(read_queue[5][i]!=1)
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
            if(status[0]==1 && read_queue[0].size()>9)
                {	int i;
                    for( i=read_queue[0].size()-2;i>read_queue[0].size()-8;i--)
                    {
                        if(read_queue[0][i]!=1)
                                break;
                    }
                    if(i==read_queue[0].size()-8)
                        {cout<<"FRAME RECIEVED AT 0";
                         while(read_queue[0].size())
                            read_queue[0].pop_front();
                         status[0]=0;
                        }
                }


            if(status[1]==1 && read_queue[1].size()>9)
                {	int i;
                    for( i=read_queue[1].size()-2;i>read_queue[1].size()-8;i--)
                    {
                        if(read_queue[1][i]!=1)
                                break;
                    }
                    if(i==read_queue[1].size()-8)
                        {cout<<"FRAME RECIEVED AT 1";
                         while(read_queue[1].size())
                            read_queue[1].pop_front();
                        status[1]=0;
                        }
                }

            if(status[2]==1 && read_queue[2].size()>9)
                {	int i;
                    for( i=read_queue[2].size()-2;i>read_queue[2].size()-8;i--)
                    {
                        if(read_queue[2][i]!=1)
                                break;
                    }
                    if(i==read_queue[2].size()-8)
                        {cout<<"FRAME RECIEVED AT 2";
                         while(read_queue[2].size())
                            read_queue[2].pop_front();
                        status[2]=0;
                        }
                }

            if(status[3]==1 && read_queue[3].size()>9)
                {	int i;
                    for( i=read_queue[3].size()-2;i>read_queue[3].size()-8;i--)
                    {
                        if(read_queue[3][i]!=1)
                                break;
                    }
                    if(i==read_queue[3].size()-8)
                        {cout<<"FRAME RECIEVED AT 3";
                         while(read_queue[3].size())
                            read_queue[3].pop_front();
                         status[3]=0;
                        }
                }

            if(status[4]==1 && read_queue[4].size()>9)
                {	int i;
                    for( i=read_queue[4].size()-2;i>read_queue[4].size()-8;i--)
                    {
                        if(read_queue[4][i]!=1)
                                break;
                    }
                    if(i==read_queue[4].size()-8)
                        {cout<<"FRAME RECIEVED AT 4";
                         while(read_queue[4].size())
                            read_queue[4].pop_front();
                         status[4]=0;
                        }
                }

            if(status[5]==1 && read_queue[5].size()>9)
                {	int i;
                    for( i=read_queue[5].size()-2;i>read_queue[5].size()-8;i--)
                    {
                        if(read_queue[5][i]!=1)
                                break;
                    }
                    if(i==read_queue[5].size()-8)
                        {cout<<"FRAME RECIEVED AT 5";
                         while(read_queue[5].size())
                            read_queue[5].pop_front();
                         status[5]=0;
                        }
                }
//----------------------------------------------------------------------------------------------------




            cout<<"next_step(0/1)-";		//next step
            cin>>x;

        }

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    vector<int> x;
    vector<int> y;
    y.push_back(1);
    y.push_back(1);
    y.push_back(0);
    y.push_back(1);
    y.push_back(1);

    x=setFrame(y,4);
    for(int i=0;i<x.size();i++)
        cout<<x[i];
    int q=decode(x,4);
    for(int i=0;i<25;i++)			//initialising the node arrays
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



    next_step();
    return a.exec();
}
