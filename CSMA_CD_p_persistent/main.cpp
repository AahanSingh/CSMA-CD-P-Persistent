#include"mainwindow.h"
#include <QApplication>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
vector<int> setFrame(vector<int> data, int rec); //rec=decimal value
int decode(vector<int> frame, int rec);

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
    return a.exec();
}
/* A-000
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
