#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>x;
    vector<int>y;
    int c,d;
    cin>>c>>d;
    int n;
    cin>>n;
    x.push_back(0);
    y.push_back(0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        x.push_back(a);
        int b;
        cin>>b;
        y.push_back(b);
    }
    x.push_back(c+1);
    y.push_back(d+1);
    print(x);
    print(y);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i=1;i<x.size();i++)
    {
        x[i]=x[i]-x[i-1]-1;
        y[i]=y[i]-y[i-1]-1;
    }
    print(x);
    print(y);
    sort(x.begin(),x.end(),greater<int>());
    sort(y.begin(),y.end(),greater<int>());
    print(x);
    print(y);

    cout<<x[0]*y[0]<<endl;
}
