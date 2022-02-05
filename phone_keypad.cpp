#include<bits/stdc++.h>
using namespace std;
void prints(char in[],char out[],int ,int);
char arr[][10]={"","","ABC","DEF","GHI","JKL","JKL","MNO","PQRS","TUV","WXYZ"};
int main()
{
 char in[1000];
 char out[1000];
 cin>>in;
 prints(in,out,0,0);

}
void prints(char in[],char out[],int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int digit=in[i]-'0';
    for(int k=0;arr[digit][k]!='\0';k++)
    {
        out[j]=arr[digit][k];
        prints(in,out,i+1,j+1);
    }
}