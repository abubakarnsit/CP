#include<bits/stdc++.h>
using namespace std;
int findlength(string str)
{
    int ml=0;
    int i=0,j=0;
    int maxl=0;
    unordered_map<char,int>m;
    while(j<str.length())
    {
        if(m.find(str[j])!=m.end() and m[str[j]]>i)
        {
            i=m[str[j]]+1;
            ml=j-i;
        }
        m[str[j]]=j;
        j++;
        ml++;
        maxl=max(ml,maxl);
        
    }
    return maxl;
}
int main()
{
    string str;
    cin>>str;
    cout<<findlength(str)<<endl;
}