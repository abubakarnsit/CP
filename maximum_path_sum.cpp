#include<iostream>
#include<vector>
using namespace std;


int find(vector<vector<int>>v,int i,int j,int n,int m,vector<vector<int>>dp)
{
    if(i==n||j==m||j<0)
    return 0;
    if(dp[i][j]!=0)
    return dp[i][j];
    int ans=0;
    ans=max(ans,v[i][j]+find(v,i+1,j-1,n,m,dp));
    ans=max(ans,v[i][j]+find(v,i+1,j+1,n,m,dp));
    ans=max(ans,v[i][j]+find(v,i+1,j,n,m,dp));
    return dp[i][j]=ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<m;j++)
        cin>>v[i][j];
    }
    int ans=0;
    for(int j=0;j<m;j++)
    {
        int a=find(v,0,j,n,m,dp);
        ans=max(a,ans);
    }
    cout<<ans<<endl;
}

