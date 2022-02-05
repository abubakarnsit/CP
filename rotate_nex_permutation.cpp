
#include <bits/stdc++.h> 
using namespace std; 
void permute(string str, string out) 
{ 
    cout<<str<<"->";
    for(int i=0;i<5;i++)
    {
	rotate(str.begin(), str.begin()+1, str.end()); 
    cout<<str<<" ";
    }
    cout<<endl;
} 

void next_permutations(string str)
{
    sort(str.begin(),str.end(),greater<int>());
    do
    {
        cout<<str<<" ";
    } while (prev_permutation(str.begin(),str.end()));
    cout<<endl;
    sort(str.begin(),str.end());
    do
    {
        cout<<str<<" ";
    } while (next_permutation(str.begin(),str.end()));
    cout<<endl;
}
int main() 
{ 
	string str = "ABC"; 
	permute(str, "");
    string str2="ABU";
    next_permutations(str); 
	return 0; 
} 
