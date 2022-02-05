#include<bits/stdc++.h>
using namespace std;
void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    cout<<s<<endl;
    reverse(s.begin()+d, s.end());
    cout<<s<<endl;
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}
 
void rightrotate(string &s, int d)
{
   leftrotate(s, s.length()-d);
   cout<<s<<endl;
}
int main()
{
    string str1 = "GeeksforGeeks";
    leftrotate(str1, 2);
    cout << str1 << endl;
 /*
    string str2 = "GeeksforGeeks";
    rightrotate(str2, 2);
    cout << str2 << endl;*/
    return 0;
}