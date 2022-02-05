#include<iostream>
using namespace std;

int profit(int *arr,int i,int j,int y,int dp[][100])
{
    if(i>j)
    return 0;
    if(i==j)
    return arr[i]*y;
    if(dp[i][j]!=0)
    return dp[i][j];
    int op1=arr[i]*y+profit(arr,i+1,j,y+1,dp);
    int op2=arr[j]*y+profit(arr,i,j-1,y+1,dp);
    return dp[i][j]=max(op1,op2);
}

int main()
{
    int n;
    cin>>n;
    int wines[n];
    for(int i=0;i<n;i++)
    {
        cin>>wines[i];
    }
    int dp[100][100]={0};
    cout<<profit(wines,0,n-1,1,dp)<<endl;
}
