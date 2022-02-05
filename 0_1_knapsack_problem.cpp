#include<iostream>
using namespace std;
int find(int *wt,int *profit,int capacity,int n);
int main()
{
   int wt[]={1,2,3,5};
   int profit[]={40,20,30,100};
   int capacity=7;
   int n=sizeof(wt)/sizeof(int);
   cout<<find(wt,profit,capacity,n)<<endl;
}
int find(int *wt,int *profit,int capacity,int n)
{
 if(n==0||capacity==0)
 return 0;
 int ans=0;
 int include=0;
 int exclude=0;
 if(wt[n-1]<=capacity)
 {
     include=profit[n-1]+find(wt,profit,capacity-wt[n-1],n-1);
 }
  exclude=find(wt,profit,capacity,n-1);
  return max(include,exclude);
}