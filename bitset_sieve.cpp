#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
bitset<10000005>b;
vector<int>v;
int n=100000005;
int main()
{
    b.set();
    b[0]=b[1]=0;
    for(long long int i=0;i*i<n;i++)
    {
        if(b[i]==1)
        {
            long long int j=i;
            while(i*j<n)
            {
                b[i*j]=0;
                j++;
            }
        }
    }
    for(long int i=0;i<n;i++)
    {
        if(b[i]==1)
        v.push_back(i);
    }
    for(int i=0;i<100;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"......."<<endl;
    cout<<v.size();
}
