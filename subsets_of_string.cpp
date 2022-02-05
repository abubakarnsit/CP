#include<bits/stdc++.h>
using namespace std;
void print(string str,int n);
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<(1<<(s.length()));i++)
    print(s,i);
}
void print(string str,int n)
{
    int i=0;
    while(n>0)
    {
        if(n&1==1)
        cout<<str[i];
        n=n>>1;
        i++;
    }
    cout<<endl;
}