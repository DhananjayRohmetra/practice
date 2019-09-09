#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,x;
    cin>>n>>m;
    vector<string>vvv;
    vector<pair<string,string> >v;
 vector<pair<int,string > >v1;
 map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        vvv.push_back(s);
    }
    sort(vvv.begin(),vvv.end());
    vector< vector < string > > vv;
    for( i=0;i<m;i++)
    {
        int x,y;

        string a,b;
        cin>>a>>b;
        cin>>x;        vv[a].push_back(b);
        mp[b]=x;
    }
    sort(vv.begin(),vv.end());
     for(int i=0;i<n;i++)
    {
        cout<<vv[i]<<"\n";
        for(int j=0;j<vv[i].size();j++)
        {
            v1.push_back({mp[vvv[i][j]],vvv[i][j]});
        }
        sort(v1.begin(),v1.end());
        for(i=0;i<v1.size();i++)
        {

            cout<<v1.first<<""<<v1.second;
        }
        v1.clear();
    }
return 0;
}
