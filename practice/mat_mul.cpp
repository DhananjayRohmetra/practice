#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define vvll vector< vll >
#define write(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
#define read(v) for(int i=0;i<v.size();i++)cin>>v[i];
#define write1(v) for(int i=1;i<v.size();i++)cout<<v[i]<<" ";
#define read1(v) for(int i=1;i<v.size();i++)cin>>v[i];
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

const ll row1 = 2, col1 = 2 , row2 =2 , col2 =2;

vvll multiply(vvll &mat1 , vvll &mat2)
{
	vvll mat;
	mat.resize(row1+1 , vll(col2+1));
	for(int i = 1 ;i<=row1 ;i++ )
	{
		for(int j = 1 ;j<=col2 ;j++)
		{
			mat[i][j] = 0;
			for(int k = 1 ; k<= col1 ; k++)
			{
				mat[i][j] += mat1[i][k]*mat2[k][j];  
			}
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	return mat;
}

int main()
{
	vvll mat1,mat2;
	mat1.resize(row1+1 , vll(col1+1));
	mat2.resize(row2+1 , vll(col2+1));
	for(int i = 1 ; i<=row1 ; i++)
	{
		for(int j = 1 ; j<= col1 ;j++)
		{
			cin>>mat1[i][j];
		}
	}
	for(int i = 1 ; i<=row2 ; i++)
	{
		for(int j = 1 ; j<= col2 ;j++)
		{
			cin>>mat2[i][j];
		}
	}
	vvll mat = multiply(mat1,mat2);
			
	return 0;
}

