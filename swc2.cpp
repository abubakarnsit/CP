#include<bits/stdc++.h>
using namespace std;
string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXWY"};
void print(string input,string output,int i=0)
{
    if(input[i]=='\0')
    {
        cout<<output<<endl;
        return;
    }
    int digit=input[i]-'0';
    if(digit==0 or digit==1)
    {
        print(input,output,i+1);
    }
    for(int k=0;k<keypad[digit].size();k++)
    {
        print(input,output+keypad[digit][k],i+1);
    }

}
int main()
{
     
   string input;
   cin>>input;
   string output="";
   print(input,output,0);
    
     
}