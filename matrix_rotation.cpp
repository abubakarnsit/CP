#include<bits/stdc++.h>
using namespace std;
void print(int **arr,int );
void transpose(int **arr,int n);
void lateral(int **arr,int n);
int main()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    arr[i]=new int [n];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
      cin>>arr[i][j];
      }
    }
    print(arr,n);
    transpose(arr,n);
    print(arr,n);
    lateral(arr,n);
    print(arr,n);
    return 0;
}
void print(int **arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void transpose(int **arr,int n)
{
    for(int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
        
    }
}
void lateral(int **arr,int n)
{
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp=arr[j][i];
            arr[j][i]=arr[j][n-i-1];
            arr[j][n-i-1]=temp;
        }

    }
}