#include<bits/stdc++.h>
using namespace std;
bool sorted(int *arr,int n);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     if(sorted(arr,n))
     cout<<"yes"<<endl;
     else
     cout<<"no";
     return 0;
}
bool sorted(int *arr,int n)
{
   if(n==1)
   return true;
   if(arr[0]<arr[1]&&sorted(arr+1,n-1))
   return true;
   return false;


}