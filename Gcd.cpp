#include<iostream>
using namespace std;
int find(int a,int b)
{
    if(a==0)
    return b;
    return find(b%a,a);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<find(a,b);
}
