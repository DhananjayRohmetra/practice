#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int main()
{
  //freopen("input.txt", "r", stdin);
  int xi,yi,xf,yf,i,j,ri,ai,bi;   
  cin>>xi>>yi>>xf>>yf;	
  map<pair<int, int>, int> mymap,visited,level;
  
  int n;
  cin>>n;   
  for(i=0;i<n;i++)
  {
  	cin>>ri>>ai>>bi;
  	for(j=ai;j<=bi;j++)
  	{
  		//cout<<ri<<" "<<j<<"\n";
  		mymap[mp(ri,j)]=1;
  		//mymap.insert(make_pair(make_pair(ri,j), 1));
	}
  }   
//cout<<mymap[mp(5,4)];
queue< pair<int,int> >myqueue;
pair<int,int>s; 
myqueue.push(mp(xi,yi));
visited[mp(xi,yi)]=1;
level[mp(xi,yi)]=0;
while(!myqueue.empty())
{
    s=myqueue.front();
    myqueue.pop();
   if(mymap[mp(s.first-1,s.second)]==1)
   {
        if(visited[mp(s.first-1,s.second)]==0)
        {
            visited[mp(s.first-1,s.second)]=1;
            level[mp(s.first-1,s.second)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first-1,s.second));
        }
   }
   if(mymap[mp(s.first+1,s.second)]==1)
   {
    	if(visited[mp(s.first+1,s.second)]==0)
        {
            visited[mp(s.first+1,s.second)]=1;
            level[mp(s.first+1,s.second)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first+1,s.second));
        }
   }
   if(mymap[mp(s.first,s.second-1)]==1)
   {
    	if(visited[mp(s.first,s.second-1)]==0)
        {
            visited[mp(s.first,s.second-1)]=1;
            level[mp(s.first,s.second-1)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first,s.second-1));
        }
   }
   if(mymap[mp(s.first,s.second+1)]==1)
   {
        if(visited[mp(s.first,s.second+1)]==0)
        {
            visited[mp(s.first,s.second+1)]=1;
            level[mp(s.first,s.second+1)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first,s.second+1));
        }
   }
   if(mymap[mp(s.first-1,s.second+1)]==1)
   {
        if(visited[mp(s.first-1,s.second+1)]==0)
        {
            visited[mp(s.first-1,s.second+1)]=1;
            level[mp(s.first-1,s.second+1)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first-1,s.second+1));
        }
   }
   if(mymap[mp(s.first+1,s.second+1)]==1)
   {
    	if(visited[mp(s.first+1,s.second+1)]==0)
        {
            visited[mp(s.first+1,s.second+1)]=1;
            level[mp(s.first+1,s.second+1)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first+1,s.second+1));
        }
   }
   if(mymap[mp(s.first-1,s.second-1)]==1)
   {
    	if(visited[mp(s.first-1,s.second-1)]==0)
        {
            visited[mp(s.first-1,s.second-1)]=1;
            level[mp(s.first-1,s.second-1)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first-1,s.second-1));
        }
   }
   if(mymap[mp(s.first+1,s.second-1)]==1)
   {
        if(visited[mp(s.first+1,s.second-1)]==0)
        {
            visited[mp(s.first+1,s.second-1)]=1;
            level[mp(s.first+1,s.second-1)]=level[mp(s.first,s.second)]+1;
            myqueue.push(mp(s.first+1,s.second-1));
        }
   }
}
if(visited[mp(xf,yf)]!=1)
{
	cout<<"-1";
}
else
{
	cout<<level[mp(xf,yf)];
}

}


