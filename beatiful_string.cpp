#include<iostream>
using namespace std;
bool issafe(string str)
{
    int arr[26]={0};
    for(int i=0;i<str.length();i++)
    {
        if(arr[str[i]-'a']!=0)
        return false;
        arr[str[i]-'a']++;
    }
    return true;
}
int main()
{
    string str;
    cin>>str;
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        for(int j=1;i+j<=str.length();j++)
        {
            string st=str.substr(i,j);
            if(issafe(st))
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
}