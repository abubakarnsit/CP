#include<bits/stdc++.h>
using namespace std;
int countsubset(vector<int>v,int i,int n,int sum)
{
    if(i==n)
    {
        if(sum==0)
        return 1;
        else
        return 0;
    }
    return countsubset(v,i+1,n,sum-v[i])+countsubset(v,i+1,n,sum);
}
int main()
{
    vector<int>v={1,2,3,4,5};
    int sum=6;
    cout<<countsubset(v,0,v.size(),sum);
}