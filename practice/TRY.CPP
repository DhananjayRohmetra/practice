#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(vector<T>&Arr)
{
    for(int i = 0 ;i<Arr.size();i++)
        cin>>Arr[i];
}
template<typename T,typename T1>
void print(map<T,T1>&Arr)
{
    for(auto i :Arr)
    {
        cout<<i.first << " "<<i.second<<"\n";
    }
}


int main()
{
    map<int,int>mp;
    for(int i= 0 ;i<5 ;i++)
        mp[i] = i;
    print(mp);
//    cout<<maxx(2,3);
}
