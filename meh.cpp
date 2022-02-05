#include<bits/stdc++.h>
using namespace std;
//function to calculate nCr
int fun(int n,int r)
{
    if(n==0 or r==0)
    return 1;
    int a=1,b=1,c=1;

    //calculating n!
    for(int i=1;i<=n;i++)
        a=a*i;

    //calculating r!
    for(int i=1;i<=r;i++)
        b=b*i;

    //calculating (n-r)!
    for(int i=1;i<=n-r;i++)
        c=c*i;

    //returning n!/(r!)(n-r)!
    return a/(b*c);
}
int main()
{
    int n;
    cin>>n;
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
            cout<<fun(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}