#include<bits/stdc++.h>
using namespace std;
struct node
{
  char ch;
  unordered_map<char,node*>m;
  bool isterm;
  node(char ch)
  {
    this->ch=ch;
    isterm=false;
  }
};
node*root;
class trie
{
    public:  
    trie()
    {
        root=new node('\0');
    }
   
    void insert(string str)
    {
        node*temp=root;
        for(auto ch:str)
        {
            if(temp->m.count(ch)==0)
            {
              temp->m[ch]=new node(ch);
             
            }
            temp=temp->m[ch];
        }
        temp->isterm=true;
    }
    bool find(string str)
    {
        node*temp=root;
        for(auto ch:str)
        {
            if(temp->m.count(ch)==0)
            return false;
            temp=temp->m[ch];
        }
        return temp->isterm;
    
    }
    void help(node*temp,int &ans)
    {
        if(temp->isterm)
        {
            cout<<temp->ch<<" ";
           ans=ans+1;
        }
        for(auto it:temp->m)
        {
            help(it.second,ans);
        }
    }
    int countwords()
    {
        int ans=0;
        node*temp=root;
        help(temp,ans);
        return ans;
    }
};
int main()
{
    string arr[]={"apple","ape","banana","news","new","cool"};
    trie t;
    for(auto str:arr)
    {
        t.insert(str);
    }
    int te;
    cin>>te;
    while(te--)
    {
        string str;
        cin>>str;
        cout<<t.find(str)<<endl;
    }
    cout<<endl<<"total words are "<<t.countwords()<<endl;

}