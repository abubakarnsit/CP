#include<iostream>
using namespace std;
int find(int n,int k, int*dp);
int main()
{
    int n,k;
    cin>>n>>k;
    int dp[n+1]={0};
    cout<<find(n,k,dp)<<endl;
}
int find(int n,int k, int*dp)
{
    if(n==0)
    {
    return 1;
    }
    if(dp[n]!=0)
    {
    return dp[n];
    }
    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
        ways+=find(n-i,k,dp);
        }
    }
    return dp[n]=ways;
}