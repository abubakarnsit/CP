#include<bits/stdc++.h>
using namespace std;
int bs(int *arr,int i,int n,int key);
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
int key;
cin>>key;
cout<<bs(arr,0,n-1,key);
}
int bs(int *arr,int i,int n,int key)
{
        if(i>n)
        return-1;
        int mid=(i+n)/2;
        if(arr[mid]==key)
        return mid;
        if(arr[mid]<key)
        return bs(arr,i+1,n,key);
        else
        return bs(arr,i,mid-1,key);
        
}