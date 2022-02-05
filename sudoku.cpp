#include<bits/stdc++.h>
using namespace std;
bool solvesuduko(int ** arr,int i, int j, int n,long long th);
bool issafe(int **arr,int i, int j, int n, int count);
long int total=0;
int main()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    cout<<" enter values for suduko and 0 for blank spaces "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;  
    long long th=1;
    solvesuduko(arr,0,0,n,th);
    cout<<"total sudukos possible is "<<total;
}
bool solvesuduko(int ** arr,int i, int j, int n,long long th)
{
    if(i==n)
    {
      cout<<" this is the "<<total<<" solution :"<<endl;
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<n;b++)
                cout<<arr[a][b]<<" ";
            cout<<endl;
        }
        cout<<endl;
        th++;
        total=total+1;
        return false;
    }
    if(j==n)
    {
        return solvesuduko(arr,i+1,0,n,th);
    }
    if(arr[i][j]!=0)
    {
        return solvesuduko(arr,i,j+1,n,th);
    }
    for(int count=1;count<=n;count++)
    {
        if(issafe(arr,i,j,n,count))
        {
          arr[i][j]=count;
          bool next=solvesuduko(arr,i,j+1,n,th);
          if(next==true)
          {
          return true;
          }
        }
    }
    arr[i][j]=0;
    return false;
}
bool issafe(int **arr,int i, int j, int n, int count)
{
    for(int a=0;a<n;a++)
    {
        if(arr[a][j]==count||arr[i][a]==count)
        return false;
    }
    int h=(i/3)*3;
    int l=(j/3)*3;
    for(int p=l;p<l+3;p++)
    {
        for(int d=h;d<h+3;d++)
        {
            if(arr[d][p]==count)
            return false;
        }
    }
    return true;
}