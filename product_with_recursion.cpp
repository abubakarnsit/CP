#include<bits/stdc++.h>
using namespace std;
int product(int,int);
int main()
{
    int a,b;
    cin>>a>>b;
    if(b<0)
    cout<<-product(a,abs(b));
    else
    {
        cout<<product(a,b);
    }
    
}
int product(int a,int b)
{
    if(b==1)
    return a;
    if(a==0||b==0)
    return 0;
    return a+product(a,b-1);
}