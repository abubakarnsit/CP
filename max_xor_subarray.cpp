#include<iostream>
#include<vector>
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
    int csum=0;
    for(int i=0;i<v.size();i++)
    {
        csum=csum^v[i];
        v[i]=csum;
    }
    int ans=0;
    int h=0,k=0;
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            int an=v[j]^v[i];
            cout<<an<<" ";
            if(an>ans)
            {
            ans=an;
            h=i;
            k=j;
            }
        }
        cout<<endl;
    }
    cout<<endl<<ans<<endl;
    cout<<"between "<<h<<" to "<<k;

}
