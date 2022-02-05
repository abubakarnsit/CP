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
    if(n<=3)
    return 1;
    return ans(n-1)+ans(n-4);
}
