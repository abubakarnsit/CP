#include<bits/stdc++.h>

using namespace std;

#define ll long long
string Find_It (int X, long long K, string S, int N) {
    S=" "+S;
    vector<set<char> >v;
    for(int i=1;i<=N;i+=X)
    {
        set<char>temp;
        for(int j=i;j<=min(N,X+i-1);j++)
        {
            temp.insert(S[j]);
        }
        v.push_back(temp);
    }
    int blocks=v.size();
    int ind=0;
    vector<vector<ll> >value(blocks,vector<ll>(X));
    ll val=1;string b="";bool flag=0;
    for(int i=blocks-1;i>=0 && !flag;i--)
    {
        set<char> :: iterator it;int j=0;
        for(it=v[i].begin();it!=v[i].end() && !flag;it++,j++)
        {
            value[i][j]=val*(j+1);
            if(value[i][j]>=K)
            {
                ind=i;
                b+=*it;if(K==value[i][j])K=0;else if(j)K-=value[i][j-1];
                flag=1;
            }
        }
        if(!flag)val=value[i][v[i].size()-1];
    }
    string a="",c="";
    for(int i=0;i<ind;i++)a+=*v[i].begin();
    for(int i=ind+1;i<blocks;i++)
    {
    	if(K==0){c+=*v[i].rbegin();continue;}
    	set<char> :: iterator it;int j=0;
        for(it=v[i].begin();it!=v[i].end();it++,j++)
        {
            if(value[i][j]>=K)
            {
                c+=*it;
                if(K==value[i][j])K=0;else if(j)K-=value[i][j-1];
                break;
            }
        }
    }
    return a+b+c;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int X;
    cin >> X;
    long long K;
    cin >> K;
    string S;
    cin>>S;

    string out_;
    out_ = Find_It(X, K, S, N);
    cout << out_;
}