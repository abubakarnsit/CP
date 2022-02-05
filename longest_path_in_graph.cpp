#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int>graph[1000];
int dp[1000];

int find(int i)
{
    if(dp[i]!=-1)
    return dp[i];
    if(graph[i].size()==0)
    return 0;
    int ans=0;
    for(auto it=graph[i].begin();it!=graph[i].end();it++)
    {
        int ds=1+find(*it);
        ans=max(ans,ds);
    }
    return dp[i]=ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int ds=find(i);
        ans=max(ans,ds);
    }
    cout<<ans<<endl;
}

