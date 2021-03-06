#include<iostream>
using namespace std;
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void generateall(char *in,char*out,int i,int j);
int main()
{
    char in[100];
    cin>>in;
    char out[100];
    generateall(in,out,0,0);
    return 0;
}
void generateall(char *in,char*out,int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return ;
    }
    int digit=in[i]-'0';
    if(digit==0 or digit==1)
    {
        generateall(in,out,i+1,j);
    }
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        out[j]=keypad[digit][k];
        generateall(in,out,i+1,j+1);
    }
    return;
}