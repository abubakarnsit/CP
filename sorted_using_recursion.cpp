#include<iostream>
using namespace std;
bool issorted(int arr[],int n);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<issorted(arr,n)<<endl;
   return 0;
} 
bool issorted(int arr[],int n)
{
    if(n==0||n==1)
    return true;
    return (arr[0]<=arr[1] and issorted(arr+1,n-1));
}