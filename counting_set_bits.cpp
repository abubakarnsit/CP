#include<iostream>
using namespace std;
int ans(int);
int method2(int);
int main()
{
    int n;
    cin>>n;
    cout<<ans(n)<<endl;
    cout<<method2(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;
    
    return 0;
}
int ans(int n)
{
    int count=0;
    while(n>0)
    {
        count+=n&1;
        n=n>>1;
    }
    return count;
}
int method2(int n)
{
    int cot=0;
    while(n>0)
    {
        cot++;
        n=n&(n-1);
    }
    return cot;
}