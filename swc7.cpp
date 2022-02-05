
#include <bits/stdc++.h>
using namespace std;

int getMinDeletions(string s)
{
  int count=0;
  int arr[26]={0};
  for(int i=0;i<s.length();i++)
  {
    if(arr[s[i]-'a']!=0)
    count++;
    arr[s[i]-'a']++;
  }
  return count;
}



int main()
{
	string str = "abcabc";
	cout << getMinDeletions(str);
	return 0;
}
