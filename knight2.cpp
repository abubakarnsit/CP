#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool issafe(int i,int j,int n,int m)
{
    if(i>=1 and i<=n and j>0 and j<=m)
    return true;
    return false;
}

int calculate(int inrow,int incol,int endrow,int endcol,int n,int m)
{
    int dx[]={2,2,-2,-2,1,1,-1,-1};
    int dy[]={1,-1,-1,1,2,-2,2,-2};
    queue<pair<pair<int,int>,int>>q;
    bool visited[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            visited[i][m]=false;
    }
    visited[inrow][incol]=true;
    q.push(make_pair(make_pair(inrow,incol),0));
    while(!q.empty())
    {
        pair<pair<int,int>,int>p=q.front();
        q.pop();
        if(p.first.first==endrow and p.first.second==endcol)
        return p.second;
        for(int i=0;i<8;i++)
        {
            if(!visited[p.first.first+dx[i]][p.first.second+dy[i]] and issafe(p.first.first+dx[i],p.first.second+dy[i],n,m))
            {
                visited[p.first.first+dx[i]][p.first.second+dy[i]]=true;
                q.push(make_pair(make_pair(p.first.first+dx[i],p.first.second+dy[i]),p.second+1));
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
               cout<<visited[i][j];
               cout<<endl;
        }
        cout<<endl;
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    cin>>i>>j;
    int e1,e2;
    cin>>e1>>e2;
    i--;
    j--;
    e1--;
    e2--;
    cout<<calculate(i,j,e1,e2,n,m)<<endl;
    return 0;
}
