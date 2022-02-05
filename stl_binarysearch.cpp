#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int b;
    cin>>b;
    if(binary_search(arr,arr+n,b))
    cout<<"found";
    else
    {
        cout<<"not found";
    }
    

}
