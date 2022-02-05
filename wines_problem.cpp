#include<bits/stdc++.h>
using namespace std;
int profit(int *arr,int i,int j,int y)
{
    if(i>j)
    {
    return 0;
    }
    int op1=arr[i]*y+profit(arr,i+1,j,y+1);
    int op2=arr[j]*y+profit(arr,i,j-1,y+1);
    return max(op1,op2);
}
int main()
{
    int arr[]={2,3,5,1,4};
    int n=sizeof(arr)/sizeof(int);
    int dp[1000][1000]={0};
    int y=1;
    cout<<"f"<<endl;
    int ans=profit(arr,0,n-1,y);
    
    cout<<ans;
    return 0;
}
