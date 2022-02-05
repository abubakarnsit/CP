#include<bits/stdc++.h>
using namespace std;
bool findpath(char maze[][10],int path[][4],int i, int j, int n,int m);
int main()
{
    char maze[10][10]={"0000",
                       "00X0",
                       "000X",
                       "0X00",};
    
    int n=4,m=4;
    int path[4][4];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        path[i][j]=0;
    }
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
          cout<<path[i][j]<<" ";
          cout<<endl;
    }
    cout<<endl;
    bool ans=findpath(maze,path,0,0,n-1,m-1);
    if(!ans)
    cout<<"not found";
    
}
bool findpath(char maze[][10],int path[][4],int i, int j, int n,int m)
{
    if(i==n&&j==m)
    {
        path[i][j]=1;
        for(int a=0;i<=n;a++)
        {
            for(int b=0;b<=m;b++)
            {
                cout<<path[a][b]<<" ";
            }
            cout<<endl; 
        }
        cout<<endl;
        cout<<endl;
        return true;
    }
    if(i>n or j>m)
    return false;

    if(maze[i][j]=='X')
    return false;

    path[i][j]=1;
    bool right=findpath(maze,path,i,j+1,n,m);
    bool down=findpath(maze,path,i+1,j,n,m);

    if(right||down)
    {
        return true;
    }
    
    path[i][j]=0;
    return false;
}