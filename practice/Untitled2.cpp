#include <iostream>
#include <math.h>

using namespace std;
void bubblesort(int N);
void swap(int *xp,int *yp);
int modInverse(int a,int m);
int power(int x,unsigned int y,unsigned int m);

int arr[1001];
int s=0;
int main()
{
    int T,i,j,t,k=0,d=0,l;
    cin>>T;
    for(i=0;i<T;i++)
    {
        int N,l=0,r;
        cin>>N;r=N-1;int brr[N];brr[0]=1;int crr[N];
        for(j=1;j<=N;j++)
        {
            brr[j]=brr[j-1]*j;
            brr[j]=brr[j]%1000000007;
        }crr[0]=1;crr[1]=1;
        for(j=2;j<=N;j++)
        {
            crr[j]=modInverse(brr[j],1000000007);
        }
        for(j=0;j<N;j++)
        {
            cin>>arr[j];
        }
        bubblesort(N);
        if(N>2)
        {
        for(j=0;j<N-1;j++)
        {
            if(arr[j]==arr[j+1])
            {
                while((arr[j]==arr[j+1])&&(j<N-1))
                {
                    d++;j++;
                }t=d;
                for(k=0;k<d;k++)
                {
                    for(l=0;l<t;l++)
                    {
                        s=s+brr[N-2-k]/(crr[j-d+l]*crr[N-2-k-j+d-l]);
                        s=s%1000000007;
                    }
                 t--;
                }
                d=0;
            }
        }
        s=s+(int)pow(2,N-1);
        s=s%1000000007;
        cout<<s<<endl;
        }
    }
    return 0;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubblesort(int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
int modInverse(int a,int m)
{
    
    
        return(power(a,m-2,m));
    
}
int power(int x,unsigned int y,unsigned int m)
{
    if(y==0)
        return 1;
    int p=power(x,y/2,m)%m;
    p=(p*p)%m;
    return(y%2==0)?p:(x*p)%m;
}


 
