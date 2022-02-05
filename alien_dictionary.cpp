#include <bits/stdc++.h>
using namespace std;
string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int>v(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto nbr:adj[i])
        {
            v[nbr]++;
        }
    }
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(v[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto nbr2:adj[node])
        {
            v[nbr2]--;
            if(v[nbr2]==0)
            q.push(nbr2);
        }
    }
    return ans;
}
string findOrder(string dict[], int N, int K) {
    vector<int>adj[K];
    for(int i=0;i<N-1;i++)
    {
            string str1=dict[i];
            string str2=dict[i+1];
            int n=str1.length();
            int m=str2.length();
            for(int i=0;i<min(n,m);i++)
            {
                if(str1[i]!=str2[i])
                {
                    adj[str1[i]-'a'].push_back(str2[i]-'a');
                    break;
                }
            }
    }
    vector<int>ans=topoSort(K,adj);
    string toreturn="";
    cout<<"order of alphabets are "<<endl;
    for(int i=0;i<ans.size();i++){
        char c=ans[i]+'a';
        cout<<c<<"->";
        toreturn=toreturn+c;
    }
    cout<<toreturn<<endl;
    return toreturn;
}