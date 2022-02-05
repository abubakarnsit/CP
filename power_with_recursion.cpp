#include<bits/stdc++.h>
using namespace std;
int p(int ,int);
int fastpower(int ,int);
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<p(a,b)<<endl;
    cout<<fastpower(a,b);
}
int p(int a,int b)
{
    if(a==1||b==0)
    return 1;
    if(b==1)
    return a;
    return a*p(a,b-1);
}
int fastpower(int a,int b)
{
    if(b==0)
    return 1;
    if(b==1)
    return a;
    if(b%2==0)
    return fastpower(a,b/2)*fastpower(a,b/2);
    if(b%2==1)
    return a*fastpower(a,b/2)*fastpower(a,b/2);
}