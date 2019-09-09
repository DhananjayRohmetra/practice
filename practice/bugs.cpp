#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int main() {
	//freopen("input.txt", "r", stdin);
	long long int  xx,yy,n,i,x,y,g=1000000000,anss;
	cin>>n;
    ordered_set d;
    for(i=0;i<n;i++){
    	cin>>x;
    	if(x==1)
    	{
    		cin>>y;
    		d.insert(y);		
		}
		else
		{
			 xx= d.order_of_key(g);
			 yy=xx-(xx/3);
			anss=*d.find_by_order(yy);
			if(anss==0)
			{
				cout<<"Not enough enemies\n";
			}
			else{
			cout<<anss<<"\n";	
			}
			
			
		}
	}
	
}
