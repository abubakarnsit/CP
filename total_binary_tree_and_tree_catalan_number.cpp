#include<iostream>
using namespace std;
#define ll long long int
ll catalan(int );
ll factorial(int );
int main()
{
    int n;
    cin>>n;
    cout<<"total binary search tree will be "<<catalan(n)<<endl;
    cout<<"total binary tree "<<factorial(n)*catalan(n)<<endl;
}
ll catalan(int n)
{
//calculating 2nCn
  ll ret=1;
  for(int i=1;i<=n;i++)
   ret=((2*n-i+1)*ret)/i;
  return(ret/(n+1));
}
ll factorial(int n)
{
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}