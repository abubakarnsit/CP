#include<bits/stdc++.h>
using namespace std;
 int main()
{
    int n;
    cin>>n;
    int arr[n],arr1[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        arr1[0]=0;
        arr1[1]=arr[0];
    for(int i=1;i<n;i++)
    {
    arr1[i+1]=arr[i-1]+arr[i];
    cout<<arr[i-1]<<" ";
    }
    cout<<arr[n-1];
    cout<<endl;
    map<int,int>m;
    int a,b;
    for(int i=0;i<n+1;i++)
    {
        if(m.find(arr1[i])==m.end())
        m[arr1[i]]=i;
        else
        {
          a=m[arr1[i]];
          b=i;
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
