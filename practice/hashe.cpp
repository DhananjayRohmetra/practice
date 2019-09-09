#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> mod_env(long long a,long long m)
{
    if(m==0)
        return pair<long long,long long> (1,0);
    pair<long long,long long> p1=mod_env(m,a%m);
    long long x=p1.second;
    long long y=p1.first-((a/m)*(p1.second));
    return pair<long long,long long> (x,y);
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    long long i=0;
    long long l1=str1.size(),mod=1000000007,hash1=0;
    long long l2=str2.size(),s=1,z3=0,z2;
    long long powe[1000],pre[1000]={0};
    for(i=0;i<l1;i++)
    {
        if(i==0)
        powe[i]=1;
        else
        {
            s=((s%mod)*29)%mod;
            powe[i]=s;
        }
    }
    for(i=0;i<l1;i++)
    {
        if(i==0)
        pre[i]=str1[i]-'a';
        else
        {
            pre[i]=(pre[i-1]+((str1[i]-'a')*powe[i])%mod)%mod;
        }
    }
    for(i=0;i<l2;i++)
    {
        if(i==0)
        hash1+=(str2[i]-'a');
        else
        {
            hash1=(hash1+((str2[i]-'a')*powe[i])%mod)%mod;
        }
    }
    for(i=0;i<=l1-l2;i++)
    {
        if(i==0)
        z2=pre[i+l2-1];
        else
        {
            pair<long long,long long> p1=mod_env(powe[i],1000000007);
            p1.first=(p1.first+mod)%mod;
            long long x=(pre[i+l2-1]-pre[i-1]+mod)%mod;
            z2=(x*(p1.first))%mod;
        }
        if(z2==hash1)
        {
            cout<<i<<"\n";
            z3++;
        }
    }
    cout<<z3<<"\n";
}
