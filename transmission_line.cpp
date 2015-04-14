#include<iostream>
#include<queue>
using namespace std;


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

int status[6]={0,0,0,0,0,0};		//listen=0   read=1   send= 2   jam=3



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

				//frame(xdata,xreceiver)		
									//del
				int arr[4]={2,0,1,1};
				for(int i=0;i<4;i++)
					xframe.push_back(arr[i]);
					
				for(int i=0;i<4;i++)
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
			for(int i=24;i>index_A;i--)
				arrayD[i]=arrayD[i-1];
			arrayD[index_D]=0;

			for(int i=0;i<index_E;i++)		//shift  E
				arrayE[i]=arrayE[i+1];
			for(int i=24;i>index_A;i--)
				arrayE[i]=arrayE[i-1];
			arrayE[index_E]=0;

			for(int i=0;i<index_F;i++)		//shift  F
				arrayF[i]=arrayF[i+1];
			arrayF[index_F]=0;	


			if(status[0]==2)
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
			
			
			if(status[1]==2)
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
			
			if(status[2]==2)
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
			
			if(status[3]==2)
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
			
			if(status[4]==2)
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
			
			if(status[5]==2)
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
				
//************************************************************************************************
			int j;
			cout<<"array A printing"<<endl;
			for(j=0;j<25;j++)
			{
				cout<<arrayA[j];
				
			}

			cout<<"array B printing"<<endl;
			for(j=0;j<25;j++)
			{
				cout<<arrayB[j];
				
			}

			cout<<"array C printing"<<endl;
			for(j=0;j<25;j++)
			{
				cout<<arrayC[j];
				
			}

			cout<<"array D printing"<<endl;
			for(j=0;j<25;j++)
			{
				cout<<arrayD[j];
				
			}

			cout<<"array E printing"<<endl;
			for(j=0;j<25;j++)
			{
				cout<<arrayE[j];
				
			}

			cout<<"array F printing"<<endl;
			for(j=0;j<25;j++)
			{
				cout<<arrayF[j];
				
			}

			
//************************************************************************************************			
//-----------------------------------------------------------------------------------------------			
											//addition of the node arrays
//----------------------------------------------------------------------------------------------




			cout<<"next_step(0/1)-";		//next step
			cin>>x;

		}

}



int main()
{												
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
	return 0;	
}
