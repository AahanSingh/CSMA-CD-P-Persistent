
#include<vector>
#include<iostream>
#include<cmath>
#include<stdlib.h>
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

int flagA=0;
int flagB=0;
int flagC=0;
int flagD=0;
int flagE=0;
int flagF=0;


int k[6];
int wait_persistance[6];

std::vector<int> send_stack[6];
deque<int> read_queue[6];
vector<int> send_frame[6];       // To store the frame so that we can send after the jamming 

                                    //LET 1 TIME SLOT BE 1 SECOND
int status[6]={0,0,0,0,0,0};		//listen=0   read=1   send= 2   jam=3     send_wait=4
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
        int R=(pow(2,k[index]))-1;
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
    {   float P=0.20;              // Akhil- As 0.015  is such a small number. The nodes will never send the data. I am assuming 20% as the prob (AAHANS -Probability that only node n will send is 1/(2^6))
        if(transmission_line[index]==0) //If line not idle goto backoff
        {
            float R=getrandom();
            if(R<=P)
            {   status[index]=2;
                k[index]=0;
            }
            else
               if(transmission_line[index]!=0)
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

                send_frame[xsender]=xframe;              //storing the frame before sending

                status[xsender]=4;
                send_stack[xsender]=xframe;

              /*  cout<<"\nsendstack";
                for(int i=0;i<send_stack[xsender].size();i++)
                    cout<<send_stack[xsender][i];
              */

            }

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

    if(status[0]==2)
        {
            if(transmission_line[index_A]<0)
                {   backoff(0);
                    send_stack[0].clear();
                    read_queue[0].clear();
                    send_stack[0]=send_frame[0];
                    status[0]=4;

                }
        }

    if(status[1]==2)
        {
            if(transmission_line[index_B]<0)
                {   backoff(1);
                    send_stack[1].clear();
                    read_queue[1].clear();
                    send_stack[1]=send_frame[1];
                    status[1]=4;

                }
        }
    if(status[2]==2)
        {
            if(transmission_line[index_C]<0)
                {   backoff(2);
                    send_stack[2].clear();
                    read_queue[2].clear();
                    send_stack[2]=send_frame[2];
                    status[2]=4;

                }
        }
    if(status[3]==2)
        {
            if(transmission_line[index_D]<0)
                {   backoff(3);
                    send_stack[3].clear();
                    read_queue[3].clear();
                    send_stack[3]=send_frame[3];
                    status[3]=4;

                }
        }
      if(status[4]==2)
        {
            if(transmission_line[index_E]<0)
                {   backoff(4);
                    send_stack[4].clear();
                    read_queue[4].clear();
                    send_stack[4]=send_frame[4];
                    status[4]=4;

                }
        }
     if(status[5]==2)
        {
            if(transmission_line[index_F]<0)
                {   backoff(5);
                    send_stack[5].clear();
                    read_queue[5].clear();
                    send_stack[5]=send_frame[5];
                    status[5]=4;

                }
        }

        if(status[0]==1)
        {    if(transmission_line[index_A]<0)
                read_queue[0].clear();

        }

        if(status[1]==1)
        {    if(transmission_line[index_B]<0)
                read_queue[1].clear();

        }

        if(status[2]==1)
        {    if(transmission_line[index_C]<0)
                read_queue[2].clear();

        }

        if(status[3]==1)
        {    if(transmission_line[index_D]<0)
                read_queue[3].clear();

        }

        if(status[4]==1)
        {    if(transmission_line[index_E]<0)
                read_queue[4].clear();

        }

        if(status[5]==1)
        {    if(transmission_line[index_F]<0)
                read_queue[5].clear();

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

                cout<<endl<<"the status of A B C D E F is  : "<<status[0]<<" "<<status[1]<<" "<<status[2]<<" "<<status[3]<<" " <<status[4]<<" "<<status[5]<<endl;
            // DELETE ABOVE PArt
            if(status[0]==3) 
            {       
                    send_stack[0].clear();
                    read_queue[0].clear();
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
                    read_queue[1].clear();
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
                    read_queue[2].clear();
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
                    read_queue[3].clear();
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
                    read_queue[4].clear();
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
                    read_queue[5].clear();
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


int main()
{
    
    vector<int> x;
    vector<int> y;
    y.push_back(1);
    y.push_back(1);
    y.push_back(0);
    y.push_back(1);
    y.push_back(1);

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

    for(int i=0;i<6;i++)
        k[i]=0;

    for(int i=0;i<6;i++)
        wait_persistance[i]=0;

    next_step();
    return 0;
}
