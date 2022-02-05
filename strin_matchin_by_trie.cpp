#include<iostream>
using namespace std;

class trie
{
    public:
    trie*arr[26];
    bool ended;
    
    trie()
    {
        for(int i=0;i<26;i++)
        {
            arr[i]=NULL;
        }
        ended=false;
    }
};


trie*root;


void add(string s)
{
    trie*curr=root;
    for(int i=0;i<s.size();i++)
    {
        if(curr->arr[s[i]-'a']==NULL)
        curr->arr[s[i]-'a']=new trie();
        curr=curr->arr[s[i]-'a'];
    }
    curr->ended=true;
}

bool find(string str)
{
    trie*curr=root;
    for(int i=0;i<str.size();i++)
    {
        if(curr->arr[str[i]-'a']==NULL)
        return false;
        curr=curr->arr[str[i]-'a'];
    }
    //if(curr->ended==false)
   // return false;
    return true;
}


int main()
{
  root=new trie();
  add("abu");
  add("bakar");
  add("abuzar");
  if(find("abu"))
  cout<<"FOUND"<<endl;
  else
  {
      cout<<"NOT FOUND"<<endl;
  }
  
}