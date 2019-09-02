#include<bits/stdc++.h>
using namespace std;
multimap<string,string>mp;
int main()
{
    freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n>>m;
    string s,check;
    map<string,vector<string> >mp;
    for(int i=0;i<n;i++)
    {
        string s1,s2,s3,s4,s5;
        cin>>s1>>s2>>s3>>s4>>s5;
        mp[s5].push_back(s1);
    }
    
    for(int i=0;i<m;i++)
    {
        string s1,s5,s3,s4,s2;
        cin>>s1>>s5>>s3>>s4>>s2;
        int flag=0;
        queue<string>q;
        while(!q.empty())
        {
            q.pop();
        }
        q.push(s2);
        while(!q.empty())
        {
            string gb=q.front();
           // cout<<gb<<"\n";
            q.pop();
            if(gb == s1)
            {
                flag=1;
                cout << "Fact\n";
                break;
            }
            for(auto it=mp[gb].begin();it!=mp[gb].end();it++)
            {
                q.push(*it);
            }
        }


        queue<string>qalter;
         while(!qalter.empty())
        {
            qalter.pop();
        }
        qalter.push(s1);
        while(!qalter.empty())
        {
            string gb=qalter.front();
            qalter.pop();
            if(gb == s2)
            {
                flag=1;
                cout << "Alternative Fact\n";
                break;
            }
            for(auto it=mp[gb].begin();it!=mp[gb].end();it++)
            {
                qalter.push(*it);
            }
        }
        if(flag == 0)
        {
            cout<<"Pants on Fire\n";
        }
    }

}