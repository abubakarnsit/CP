#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr(1);
    cout<<arr.size();
    arr.push_back(1);
    arr.push_back(2);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    arr.insert(arr.begin(),3);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";

} 