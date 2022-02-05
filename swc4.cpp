#include<bits/stdc++.h>
using namespace std;
bool issafe(int arr[][20],int i,int j,int n)
{
    for(int k=0;k<i;k++)
    {
        if(arr[k][j]==1)
        return false;
    }
    int x=i,y=j;
    while(x>=0 and y>=0)
    {
        if(arr[x][y]==1)
        return false;
        x--;y--;
    }
    x=i,y=j;
    while(x>=0 and y<n)
    {
        if(arr[x][y]==1)
        return false;
        x--;y++;
    }
    return true;
}
void print(int arr[][20],int n,int &count)
{
    cout<<count<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    count++;
    cout<<endl<<endl;
}
bool solvequeen(int arr[][20],int n,int i,int &count)
{
    if(i==n)
    {
        print(arr,n,count);
        return false;
    }
    for(int j=0;j<n;j++)
    {
        if(issafe(arr,i,j,n))
        {
            arr[i][j]=1;
            bool success=solvequeen(arr,n,i+1,count);
            if(success)
                return true;
            arr[i][j]=0;
            
        }
        
    }
    
    return false;
}
int main()
{
    int arr[20][20]={0};
    int n;
    cin>>n;
    int count=1;
    solvequeen(arr,n,0,count);

}