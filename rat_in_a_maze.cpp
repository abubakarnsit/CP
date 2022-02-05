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
    findpath(maze,path,0,0,n-1,m-1);
    
}
bool findpath(char maze[][10],int path[][4],int i, int j, int n,int m)
{
    if(i==n&&j==m)
    {
        path[i][j]=1;
        for(int a=0;a<4;a++)
        {
            for(int b=0;b<4;b++)
            {
                if(path[a][b]==1)
                cout<<"1 ";
                else
                cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl;
       // exit(0); // if u just want to print one path exit(0);terminates the program irrespective of where it is
        path[i][j]=0;
        return false;
    }

    if(maze[i][j]=='X')
    return false;

    if(i>n||j>m)
    return false;

    path[i][j]=1;

    bool next=findpath(maze,path,i+1,j,n,m);
    bool next2=findpath(maze,path,i,j+1,n,m);

    if(next2||next)
    return true;

    path[i][j]=0;

    return false;
}