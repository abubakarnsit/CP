#include<iostream>
using namespace std;
long long int power(int ,int);
int main()
{
    int a,b;
    cin>>a>>b;
    long long int ans=power(a,b);
    cout<<ans;
}
long long int power(int a,int b)
{
    if(b==0)
    return 1;
    long long int smaller=power(a,b/2);
    smaller*=smaller;
    if(b&1)
    return a*smaller;
    return smaller;
}