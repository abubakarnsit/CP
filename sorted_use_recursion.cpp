#include<bits/stdc++.h>
using namespace std;
bool issorted(int *arr,int i,int n)
{
if(i>=n-1)
return true;
if(arr[i]>=arr[i-1] and issorted(arr,i+1,n))
return true;
return false;
}
int linearsearch(int*arr,int n,int key,int i)
{
 if(i>=n)
 return -1;
 if(arr[i]==key)
 return i;
 return linearsearch(arr,n,key,i+1);
}
int lastocc(int *arr,int n,int key,int i)
{
    if(i<0)
    return -1;
    if(arr[i]==key)
    return i;
    return lastocc(arr,n,key,i-1);
}
void allocc(int *arr,int n,int key,int i)
{
    if(i>=n)
    return ;
    if(arr[i]==key)
    cout<<i<<endl;
    allocc(arr,n,key,i+1);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int key;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<issorted(arr,1,n)<<endl;
    cin>>key;
    cout<<linearsearch(arr,n,key,0)<<endl;
    cout<<lastocc(arr,n,key,n-1)<<endl;
    allocc(arr,n,key,0);
}