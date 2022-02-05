#include<bits/stdc++.h>
using namespace std;
bool issafe(int **arr,int i,int j,int n);
bool solveNqueen(int **arr,int i,int n,int ,int&);
long int count=0;
int main()
{
    int n;
    cout<<"enter the size of n queen board ";
    cin>>n;
    int **arr;
    arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }
    int total=0;
    solveNqueen(arr,0,n,total);
    cout<<"total count is "<<total<<endl;
}
bool solveNqueen(int **arr,int i,int n,int &total)
{
    if(i==n)
    {
     cout<<count<<" solution is: "<<endl;
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<n;b++)
            {
                if(arr[a][b]==1)
                cout<<"Q ";
                else
                cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl;
        count++;
        total++;
        return false;
    }
    for(int j=0;j<n;j++)
    {
        if(issafe(arr,i,j,n))
        {
          arr[i][j]=1;
          bool next=solveNqueen(arr,i+1,n,total);
          if(next)
          {
          return true;
          }
          
        }
        arr[i][j]=0;
       
    } 
 return false;
}
bool issafe(int **arr,int i,int j,int n)
{
    int x=i;
    int y=j;
    while(x>=0&&y>=0)
    {
        if(arr[x][y]==1)
        return false;
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0&&y<n)
    {
        if(arr[x][y]==1)
        return false;
        x--;
        y++;
    }
    x=i;
   for(int row=0;row<i;row++)
   {
       if(arr[row][j]==1)
       return false;
   }
    return true;
}