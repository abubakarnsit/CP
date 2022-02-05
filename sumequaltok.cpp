#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int arr[]={1,3,2,1,4,1,3,2,1,1};
    int n=sizeof(arr)/sizeof(int);
    int k=8;
    int i=0;
    int j=0,sum=0;
    while(j<n)
    {
      sum=sum+arr[j];
      j++;
      while(sum>k and i<j)
      {
          sum-=arr[i];
          i++;
      }
      if(sum==k)
      cout<<i<<" "<<j-1<<endl; 
    }
}