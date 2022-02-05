#include<iostream>
#include<set>
#include <iostream>
#include <fstream>
using namespace std;
#define N 100000
int count=0;
void printall(char* str,int i,set<string>&s);
int main()
{
    char str[N];
    cin>>str;
    ofstream infile ("example.txt");
    set<string>s;
    printall(str,0,s);
    cout<<count;
    for(auto it=s.begin();it!=s.end();it++)
    {
    infile<<*it<<endl;
    }
    cout<<s.size()<<endl;
}
void printall(char *str,int i,set<string>&s)
{
    if(str[i]=='\0')
    {
        cout<<str<<endl;
        count++;
        string a(str);
        s.insert(a);
        return;
    }
    for(int j=i;str[j]!='\0';j++)
    {
        swap(str[i],str[j]);
        printall(str,i+1,s);
        swap(str[i],str[j]);
    }
    return;
}