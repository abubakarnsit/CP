#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define mod 100000000009
using namespace std;
int dp[100][100001];
long long int distribute(int n, int k ,vector<long long int>v)
{
    if(k==0)
    return 1;
    if(k!=0 and n==0)
    return 0;
    if(dp[n][k]!=-1)
    return dp[n][k];
    long long int count=0;
    for(int i=0;i<=v[n];i++)
    {
        count=(mod+count+distribute(n-1,k-i,v))%mod;
    }
    return dp[n][k]=count;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<long long int>v(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>v[i+1];
    }
    
    memset(dp,-1,sizeof(dp));
    cout<<distribute(n,k,v);
}

