#include <bits/stdc++.h>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
bool issafe(int i,int j,int n ,int m)
{
    if(i<n and i>=0 and j<m and j>=0)
    return true;
    return false;
}
void dfs(int i,int j,int n,int m,bool**visited,char **arr)
{
    visited[i][j]=true;
    for(int l=0;l<4;l++)
    {
        if(issafe(i+dx[l],j+dy[l],n,m))
        {
            //char c=arr[i+dx[l]][j+dy[l]];

            if(visited[i+dx[l]][j+dy[j]]==false)
            {
            cout<<i+dx[l]<<" "<<j+dy[l]<<endl;
            dfs(i+dx[l],j+dy[l],n,m,visited,arr);
            }
        }
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    string arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    bool**visited=new bool* [n];
	    for(int i=0;i<n;i++)
	    visited[i]=new bool[m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        visited[i][j]=false;
	    }
	    char **arr2=new char*[n];
	    for(int i=0;i<n;i++)
	    arr2[i]=new char[m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
            {
	        arr2[i][j]=arr[i][j];
            cout<<arr2[i][j];
            }
            cout<<endl;
	    }
	   int count=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        
	        {
                char c=arr2[i][j];
	            if(!visited[i][j])
	            {
	                dfs(i,j,n,m,visited,arr2);
	                count++;
	            }
	        }
	    }
	    cout<<count<<endl<<endl<<endl;
        
	}
	return 0;
}