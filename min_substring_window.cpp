#include<iostream>
#include<climits>
using namespace std;
string match(string str,string pat);

int main()
{
    string str,pat;
    cin>>str>>pat;
    cout<<match(str,pat)<<endl;
}
string match(string str,string pat)
{
    int len1=str.length();
    int len2=pat.length();
    int pat_map[256]={0};
    int str_map[256]={0};
    for(int i=0;i<len2;i++)
    {
        pat_map[pat[i]]+=1;
    }
    int start=0;
    int len=INT_MAX;
    int start_index=-1;
    int count=0;
    for(int j=0;j<len1;j++)
    {
        str_map[str[j]]+=1;
        if(pat_map[str[j]]!=0 and str_map[str[j]]<=pat_map[str[j]])
        count+=1;
        if(count==len2)
        {
            while(str_map[str[start]]>pat_map[str[start]] or pat_map[str[start]]==0)
            {
                if(str_map[str[start]]>pat_map[str[start]])
                str_map[str[start]]-=1;
                start++;
            }
            int len_window=j-start+1;
            if(len>len_window)
            {
                len=len_window;
                start_index=start;
            }
        }  
    }
    if(start_index==-1)
    return "NO WINDOW FOUND";
    return str.substr(start_index,len);   
}