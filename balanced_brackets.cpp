#include<iostream>
using namespace std;
#define N 100000
void printall(int n, char *out,int idx,int open,int close);
int main()
{
    int n;
    cin>>n;
   char out[N];
   int idx=0;
    printall(n,out,idx,0,0);
}
void printall(int n, char *out,int idx,int open,int close)
{
    if(idx==2*n)
    {
        out[idx]='\0';
        cout<<out<<endl;
        return ;
    }
    if(open<n)
    {
        out[idx]='(';
        printall(n,out,idx+1,open+1,close);

    }
    if(close<open)
    {
    out[idx]=')';
    printall(n,out,idx+1,open,close+1);
    }
    return;
}