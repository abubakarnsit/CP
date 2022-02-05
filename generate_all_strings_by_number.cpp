#include<iostream>
using namespace std;
#define N 100000
void generateall(char*in,char*out,int i,int j);
int main()
{
  char in[N];
  cin>>in;
  char out[N];
  generateall(in,out,0,0);
}
void generateall(char*in,char*out,int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int digit=in[i]-'0';
    //taking one digit at a time
    char ch='A'+digit-1;
    out[j]=ch;
    generateall(in,out,i+1,j+1);

    //taking two digits at a time
    if(in[i+1]!='\0')
    {
      int a=in[i]-'0';
      int b=in[i+1]-'0';
      int digit=a*10+b;
      if(digit<=26)
      {
          char ch='A'+digit-1;
          out[j]=ch;
          generateall(in,out,i+2,j+1);
      }
    }
    return;

}
