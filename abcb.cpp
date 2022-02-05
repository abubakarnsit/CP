#include<bits/stdc++.h>
using namespace std;
void helper(string pat, int M,int lps[])
{
    long long len = 0,i=1;
    lps[0] = 0;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else 
            {
                lps[i] = len;
                i++;
            }
        }
    }
}
 
int search(string pat, string txt)
{
    long long M = pat.length();
    long long N = txt.length();
    int lps[M];
    long long j = 0;
    helper(pat, M, lps);
    long long i = 0,res=0,next_i=0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++,i++;
        }
        if (j == M)
        {
            j = lps[j - 1];
            res++;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}
int main()
{
    string a,b;
    cin>>a>>b;
    char arr[26]={0};
    for(long long i=0;i<a.length();i++)
        arr[a[i]-'a']++;
    long long ans1=0,ans2=0;
    for(int i=0;i<26;i++)
        if(arr[i]>1)
        ans1++;
    ans2=search(b,a);
    cout<<ans1<<endl<<ans2;
}