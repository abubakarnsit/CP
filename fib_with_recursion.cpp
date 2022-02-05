#include<bits/stdc++.h>
using namespace std;
int fib(int);
int fact(int );
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cout<<fib(i)<<" ";
    cout<<endl<<fib(n)<<endl;
    cout<<"factorial of the number is "<<fact(n);
}
int fib(int n)
{
    if(n==0||n==1)
    return 1;
    else
    {
        return fib(n-1)+fib(n-2);
    }
    
}
int fact(int n)
{
    if(n==1)
    return 1;
    else return n*fact(n-1);
}