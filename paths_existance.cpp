#include <bits/stdc++.h>
using namespace std;
bool issafe(int i,int j,int n)
{
    if(i>=0 and i<n and j>=0 and j<n)
    return true;
    return false;
}
bool bfs(int startrow,int startcol,bool**visited,int**arr,int n)
{
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    visited[startrow][startcol]=true;
    queue<pair<int,int>>q;
    q.push({startrow,startcol});
    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        if(arr[p.first][p.second]==2)
        return true;
        for(int l=0;l<4;l++)
        {
            if(issafe(p.first+dx[l],p.second+dy[l],n) and !visited[p.first+dx[l]][p.second+dy[l]] and arr[p.first+dx[l]][p.second+dy[l]]!=0)
            {
                q.push({p.first+dx[l],p.second+dy[l]});
                visited[p.first+dx[l]][p.second+dy[l]]=true;
            }
        }
    }
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int**arr=new int*[n];
	    bool**visited=new bool*[n];
	    for(int i=0;i<n;i++)
	    {
	        arr[i]=new int[n];
	        visited[i]=new bool[n];
	    }
	    int startrow,startcol;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            int a;
	            cin>>a;
	            arr[i][j]=a;
	            if(a==1)
	            {
	                startrow=i;
	                startcol=j;
	            }
	            visited[i][j]=false;
	        }
	    }
	    
	    cout<<bfs(startrow,startcol,visited,arr,n)<<endl;
	}
	return 0;
}