#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>>dist)
{
    for(int i=0;i<dist.size();i++)
    {
        for(int j=0;j<dist[i].size();j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<vector<int>>bellmen(vector<vector<int>>dist)
{
    int n=dist.size();
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
        print(dist);
    }
    return dist;
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dist(n,vector<int>(n,2e4));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            dist[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        dist[x][y]=w;
    }
    print(dist);
    vector<vector<int>>ans=bellmen(dist);
    print(ans);

}
