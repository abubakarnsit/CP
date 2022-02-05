#include<iostream>
using namespace std;
#define N 100000
void printall(char *input,char *output,int,int);
int main()
{
    char inp[N];
    cin>>inp;
    char out[N];
    printall(inp,out,0,0);
    return 0;
}
void printall(char *input,char *output,int i,int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return ;
    }
    output[j]=input[i];
    printall(input,output,i+1,j+1);
    
    printall(input,output,i+1,j);
    
}