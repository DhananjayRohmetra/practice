#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool isPerfectSquare(long double x) ;
bool isPerfectSquare(long double x) 
{   
  long double sr = sqrt(x);  
  
  return ((sr - floor(sr)) == 0); 
} 
int main()
{
//	ll n,o,e,s2=0,s3=0,s5=0,s9=0s7=0;
//	cin>>n>>o>>e;
//	w=n;
//	while(w%2==0)
//	{
//		s2++;
//		w=w/2;
//	}
//		w=n;
//	while(w%3==0)
//	{
//		s3++;
//		w=w/3;
//	}
//		w=n;
//	while(w%5==0)
//	{
//		s5++;
//		w=w/5;
//	}
//		w=n;
//	while(w%7==0)
//	{
//		s7++;
//		w=w/7;
//	}
//		w=n;
//	while(w%9==0)
//	{
//		s9++;
//		w=w/9;
//	}
//		
//	if(n==0 )
//	{
//		cout<<"YES\n";
//	}
//	else if(n%2!=0)
//	{
//		if(e==0 )
//		{
//			cout<<"YES\n";
//		}
//		else
//		{
//			cout<<"NO\n";
//		}
//	}
//	else
//	{
//		if(o>=s5+s7+s9 && e==s2)
//		{
//				cout<<"YES\n";
//		}
//			else
//		{
//			cout<<"NO\n";
//		}
//	}
//	


int t;
cin>>t;
while(t--)
{
	char str[100009],s[1002][1002],bstr[100009];
	cin>>str;
	 int length,i,j,k,flag=0,n,x,y;
	long double len=strlen(str);
     int len1=strlen(str);
    if(isPerfectSquare(len))
	{
		length=sqrt(len);
	}
	else
	{
		length=1+sqrt(len);
	}
	
	k=0;
	cout<<length;
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{if(k<=len1-1){
		
			s[i][j]=char(str[k]);
			k++;}
			else
			{
				s[i][j]='*';
			}
		}
	
	}
    
	cin>>n;
   
 int arr[n+4];
	for(i=0;i<length;i++)
	{
		arr[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		swap(arr[x-1],arr[y-1]);
	}
    int h=0,g=0;
     if(isPerfectSquare(len))
	{
		for(i=0;i<length;i++)
	{
         h=i;
		for(j=0;j<(length);j++)
        {
          
            if(s[j][arr[i]-1]!='*'){
        bstr[h]=s[j][arr[i]-1];
                h+=length;
               
            }
            
        }
               
    }
    
    for(i=0;i<len1;i++)
    {cout<<bstr[i];}
   
        cout<<endl;
	}
    else{
	for(i=0;i<length;i++)
	{
         h=i;
		for(j=0;j<(len1/length);j++)
        {
          
            if(s[j][arr[i]-1]!='*'){
        bstr[h]=s[j][arr[i]-1];
                h+=length;
               
            }
            
        }
               
    }

    for(i=0;i<length*(len1/length);i++)
    {cout<<bstr[i];}
    for(i=0;i<n;i++)
    {
        if(s[len1/length][arr[i]-1]!='*'){
            cout<<s[len1/length][arr[i]-1];}
    }
        cout<<endl;
		}
}
}
