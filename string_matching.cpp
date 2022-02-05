#include<bits/stdc++.h>
using namespace std;
int solve(string a,string b)
{
    int arr1[26]={0};
    int arr2[26]={0};
    for(int i=0;i<a.length();i++)
    {
        arr1[a[i]-97]++;
    }
    for(int i=0;i<b.length();i++)
    {
        arr2[b[i]-97]++;
    }
    int ans=0;
    for(int i=0;i<26;i++)
    {
        ans=ans+(arr1[i]*arr2[i]);
    }
    return ans;
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
}