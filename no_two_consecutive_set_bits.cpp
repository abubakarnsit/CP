#include<iostream>
using namespace std;
int ans(int);
int main()
{
    int n;
    cin>>n;
    cout<<ans(n);
}
int ans(int n)
{
    if(n==1)
    return 1;
    if(n==2)
    return 3;
    return ans(n-1)+ans(n-2);
}
