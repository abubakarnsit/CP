#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void prime(int *arr,int);
void print(int *arr,int);
int main()
{
    int a,b;
    cout<<"enter two numbers between which u want to find the numbers of prime"<<endl;
    cin>>a>>b;
    int n=max(a,b);
    int arr[n+1];
    for(int i=0;i<=n;i++)
    arr[i]=1;
    prime(arr,n);
    print(arr,n+1);
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for (int i=1;i<n+1;i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }
        for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"the total number of prime number between "<< max(a,b)<< " and "<<min(a,b)<<" is "<<arr[max(a,b)]-arr[min(a,b)-1];
}
void print(int *arr,int n)
{
 for (int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
        cout<<i<<" ";
        }
    }
cout<<endl;
}
void prime(int *arr,int n)
{
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i*i<=n;i++)
    {
        if(arr[i]==1)
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                arr[j]=0;
            }
        }
    }
}
