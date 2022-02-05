#include<iostream>
using namespace std;
int ans(int*dp,int);
int main()
{
    int n;
    cin>>n;
    int dp[n+1]={0};
    cout<<ans(dp,n)<<endl;
}
int ans(int *dp,int n)
{
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        if(i%6==0)
        {
            dp[i]=min(dp[i/2],min(dp[i/3],dp[i-1]))+1;
        }
        else if(i%3==0)
        {
            dp[i]=min(dp[i/3],dp[i-1])+1;
        }
        else if(i%2==0)
        {
            dp[i]=min(dp[i/2],dp[i-1])+1;
        }
        else
        {
            dp[i]=dp[i-1]+1;
        }
    }
    return dp[n];
}