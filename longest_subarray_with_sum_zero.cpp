#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    v.push_back(0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    unordered_map<int,int>m;
    int csum=0;
    int ans=0;
    cout<<v.size()<<endl;
    for(int i=1;i<v.size();i++)
    {
        csum=csum+v[i];
        cout<<csum<<" ";
        if(m.find(csum)!=m.end())
        {
            
            int d=i-m[csum];
            if(d>ans)
            ans=d;
            
        }
        else
        {
            m[csum]=i;
        }
        
    }
    cout<<endl<<ans<<endl;

}