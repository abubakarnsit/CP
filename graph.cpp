#include<iostream>
#include<list>
using namespace std;
class graph
{
    int V;
    list<int>*l;
    public:
    graph(int v)
    {
        V=v;
        l=new list<int>[v];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void show()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(auto it=l[i].begin();it!=l[i].end();it++)
            {
                cout<<*it<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph  g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,2);
    g.addedge(2,3);
    g.show();
}