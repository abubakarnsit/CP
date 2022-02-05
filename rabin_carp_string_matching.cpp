#include<bits/stdc++.h>
using namespace std;
#define prime 3
int has(string str1,string str2);
int calhas(string str1,string str2,int i,int prev);
bool equal(string str1,string str2,int i);
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<"length of string 1 "<<str1.length()<<endl;
    cout<<"length of string 2 "<<str2.length()<<endl;
    int d=has(str1,str2);
     int g=has(str2,str2);
     int count=0;
     if(d==g&equal(str1,str2,0))
     {
         count++;
         cout<<count<<" occurance from index "<<0<<endl;
     }
     int fg=(str1.length()-str2.length());
     for(int i=1;i<=fg;i++)
     {
         int x=calhas(str1,str2,i,d);
         if(x==g&equal(str1,str2,i))
         {
             count++;
             cout<<count<<" occurance from index "<<i<<endl;
         }
         d=x;
     }
    return 0;
}
int has(string str1,string str2)
{
    int c=0;
    for(int i=0;i<str2.length();i++)
    c=c+str1[i]*pow(prime,i);
    return c;
}
int calhas(string str1,string str2,int i,int prev)
{
    prev=prev-str1[i-1]*pow(prime,0);
    prev=prev/prime;
    prev=prev+str1[i+str2.length()-1]*pow(prime,str2.length()-1);
    return prev;
}
bool equal(string str1,string str2,int i)
{
    int flag=0;
    for(int j=0;j<str2.length();j++)
    {
        if(str1[j+i]!=str2[j])
        {
        flag++;
        break;
        }
    }
    if(flag!=0)
    return false;
    return true;
}