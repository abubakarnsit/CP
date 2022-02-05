#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    cout<<str<<endl;
    vector<string>words;
    stringstream s(str);
    string temp;
    while(s>>temp)
    {
        words.push_back(temp);
    }
    for(auto abc:words)
    {
        cout<<abc<<endl;
    }
    char arr[]="abu is very much cool, then lets code";
    char*token=strtok(arr," ");
    while(token!=NULL)
    {
        cout<<token<<endl;
        token=strtok(NULL," ");
    }

}