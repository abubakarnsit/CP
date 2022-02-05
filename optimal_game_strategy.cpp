#include<iostream>
using namespace std;
int find(int i,int j,int*arr,int dp[][100])
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int op1=arr[i]+min(find(i+1,j-1,arr,dp),find(i+2,j,arr,dp));
    int op2=arr[j]+min(find(i+1,j-1,arr,dp),find(i,j-2,arr,dp));
    int newans=max(op1,op2);
    return dp[i][j]=newans;

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int dp[100][100];
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
    int got=find(0,n-1,arr,dp);
    int ans=0;
    for(int i=0;i<n;i++)
    ans+=arr[i];
    cout<<got<<" "<<ans-got;
    
}
