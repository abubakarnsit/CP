#include<bits/stdc++.h>
using namespace std;
bool find(int);
int	main()
{
    int n;
    cin>>n;
    if(find(n))
    cout<<"prime number"<<endl;
    else
    {
        cout<<"not a prime number"<<endl;
    }
    
    return 0;
}
bool find(int n)
{
    if(n==1||n==2||n==3)
    return 1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
