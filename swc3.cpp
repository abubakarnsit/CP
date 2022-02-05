#include<bits/stdc++.h>
using namespace std;
void fun(string s)
{
    char a=s[0];
    s[0]=s[2];
    s[2]=a;
    cout<<s<<endl;
}
int main()
{
    string s="abu";
    cout<<s<<endl;
    fun(s);
    cout<<s<<endl;
}