#include <bits/stdc++.h>
using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);

		int i,n;
		cin>>n;
   		int arr[n+1],x,crr[n+1],index[n+1],parent[n+1];
   		memset(crr,-1,sizeof(crr));
   		memset(parent,-1,sizeof(parent));
   		for(i=0;i<n;i++)
   		{
   			cin>>arr[i];
   			index[arr[i]]=i;
		}
		for(i=0;i<n;i++)
   		{
   			cin>>x;
   			crr[arr[i]]=x;
		}
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		i=s+1;
		for(;i<crr[s];)
		{
	
		parent[index[i]]=index[s];
		q.push(i);
		i=crr[i];
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<parent[i]+1<<"\n";
	}
}



