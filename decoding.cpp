#include<iostream>
#include<vector>
#include<math.h> 

using namespace std;
vector<int> decode(vector<int> frame, int rec)
{
    vector<int> data;
    int len=frame.size();
    int cmp=0;
    for(int i=8;i<=10;i++)
    {
        cmp*=10;
        cmp+=frame[i];
    }
    //cmp is in binary form
    int dec=0;
    int c=0;
    while(cmp!=0)
    {
        int d=cmp%10;
        dec+=d*pow(2,c);
        c++;
        cmp/=10;
    }
    //dec represent decimal form of cmp
    if(rec==dec)
    {
        int k=0;
        for(int i=11;i<=frame.size()-9;i++)
        {   
            if(k==5)
            {
                k=0;
            }
            else
            {
                if (frame[i]==1)
                {
                    k++;
                }
                else
                    k=0;
                data.push_back(frame[i]);
            }
        }
        cout<<endl<<"The data received at station "<<rec<<" is : ";
        return data;   
    }
}
int main()
{
    vector<int> frame;
    //flag
    frame.push_back(0);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(0);
    //rec
    frame.push_back(0);
    frame.push_back(1);
    frame.push_back(1);
    //data
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(0);
    frame.push_back(1);
    //flag
    frame.push_back(0);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(1);
    frame.push_back(0);

    vector<int> data=decode(frame,3);
    for(int i=0;i<data.size();i++)
        cout<<data[i];
    return 0;
}