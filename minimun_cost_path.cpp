#include <bits/stdc++.h>
using namespace std;
bool possible(int i,int j,int n)
{
    if(i<n and i>=0 and j<n and j>=0)
    return true;
    return false;
}
int dijkstra(int i,int j,int**arr,int n)
{
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    int dist[n][n];
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<n;l++)
        {
            dist[k][l]=INT_MAX;
        }
    }
    set<pair<int,pair<int,int>>>s;
    s.insert(make_pair(arr[i][j],make_pair(i,j)));
    while(!s.empty())
    {
        pair<int,pair<int,int>>p=*(s.begin());
        s.erase(s.begin());
        int dis=p.first;
        int x=p.second.first;
        int y=p.second.second;
        dist[x][y]=dis;
        cout<<dis<<","<<x<<","<<y<<"-->"<<endl;
        for(int ko=0;ko<4;ko++)
        {
            if(possible(x+dx[ko],y+dy[ko],n) and dis+arr[x+dx[ko]][y+dy[ko]]<dist[x+dx[ko]][y+dy[ko]])
            {
                auto f=s.find(make_pair(dist[x+dx[ko]][y+dy[ko]],make_pair(x+dx[ko],y+dy[ko])));
                if(f!=s.end())
                s.erase(f);
                dist[x+dx[ko]][y+dy[ko]]=dis+arr[x+dx[ko]][y+dy[ko]];
                s.insert(make_pair(dis+arr[x+dx[ko]][y+dy[ko]],make_pair(x+dx[ko],y+dy[ko])));
            }
        }
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<n;b++)
            cout<<dist[a][b]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return dist[n-1][n-1];
    
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int**arr=new int* [n];
        for(int i=0;i<n;i++)
        arr[i]=new int [n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>arr[i][j];
        }
        cout<<dijkstra(0,0,arr,n)<<endl;
    }
	return 0;
}