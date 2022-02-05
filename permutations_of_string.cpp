#include<bits/stdc++.h>
using namespace std;
void print(char *,int );
int main()
{
    char in[1000];
    char out[1000];
    cin>>in;
    print(in,0);
}
void print(char *in,int j)
{
    if(in[j]=='\0')
    {
        cout<<in<<",";
        return ;
    }
    for(int i=j;in[i]!='\0';i++)
    {
        swap(in[i],in[j]);
        print(in,j+1);
        swap(in[i],in[j]);
    }
}