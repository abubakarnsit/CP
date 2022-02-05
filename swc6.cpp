#include<bits/stdc++.h>
using namespace std;
int findways(int n,int k,int dp[])
{
    if(n==0)
    return 1;
    if(n<0)
    return 0;
    if(dp[n]!=0)
    return dp[n];
    int ans=0;
    for(int j=1;j<=k;j++)
    {
            ans=ans+findways(n-j,k,dp);
    }
    return dp[n]=ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int dp[n+1]={0};
    dp[0]=1;
    cout<<findways(n, k,dp)<<endl;
}