#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string str;
    cin>>n;
    cin>>str;
    string ans="";
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '1')
        {
            ans+='a';
        }
        if(str[i] == '2')
        {
            ans+='b';
            ans+='b';
        }
        if(str[i] == '3')
        {
            ans+='a';
            ans+='b';
        }
        if(str[i] == '4')
        {
            for(int i=0;i<ans.length();i++)
            {
                if(ans[i] == 'a')
                {
                    ans[i]='b';
                }
                else
                {
                   ans[i]='a'; 
                }
                
            }
        }
    }
    cout<<ans;
}