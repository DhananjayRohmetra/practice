#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int arrival[num+1],run[num+1],fixedTime,wt[1000],i;
    for(i=0;i<num;i++)
    {
        cin>>arrival[i];
    }
    for(i=0;i<num;i++)
    {
        cin>>run[i];
    }
    cin>>fixedTime;
    int t=0,t1=0,g=0,f=0,z,z1,s=0;
    queue<pair<int,int> > qu;
    pair<int,int> p;
    while(t!=-1)
    {
        t1=0;
        f=0;
        while(t1!=fixedTime)
        {
            if(qu.empty() && t!=0)
            {
                g=1;
                break;
            }
            if(!qu.empty())
            {
                p=qu.front();
                z=p.first;
                z1=p.second;
                z=z-1;
                if(z==0)
                {
                    f=1;
                    qu.pop();
                    wt[z1]=t+t1+1-arrival[z1]-run[z1];
                }
                else
                {
                    if(t1==fixedTime-1)
                    {
                        qu.pop();
                        qu.push({z,z1});
                    }
                }
                t1++;
            }
            for(i=0;i<num;i++)
            {
                if(arrival[i]==t+t1)
                {
                    qu.push({run[i],i});
                }
            }
            if(f==1)
                break;
        }
        t=t+t1;
        if(g==1)
            break;
    }
    for(i=0;i<num;i++)
    {
        s+=wt[i];
    }
    cout<<(1.0*s)/num;
}
