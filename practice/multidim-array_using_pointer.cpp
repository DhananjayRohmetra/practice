#include<bits/stdc++.h>
using namespace std;
int main()
{
    int (*ptr)[4],x,i,j;
    for(i=0;i<3;i++)
    {
        //for(j=0;j<2;j++)
        //{
            cin>>x;
            *(ptr+i)=x;
        //}
    }
    for(i=0;i<3;i++)
    {
        //for(j=0;j<2;j++)
        //{
            //cin>>x;
            cout<<*(ptr+i)<<" ";
       // }
        //cout<<"\n";
    }
}
