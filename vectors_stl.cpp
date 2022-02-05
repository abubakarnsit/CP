#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>);
int main()
{
    int arr[]={900,900,900,900,900};
    vector<int>a(5,100);
    vector<int>b{0,1,2,3,4,5,7,8,9,10,11,12,13,14};
    vector<int>c;
    vector<int>d(arr,arr+2);
    c.push_back(6);
    print(a);
    print(b);
    print(c);
    print(d);
    b.erase(b.begin()+2);
    print(b);
    b.insert(b.begin()+2,2);
    print(b);
    b.erase(b.begin()+3,b.begin()+6);
    print(b);

}
void print(vector<int>a)
{
    for (int d:a)
    {
        cout<<d<<",";
    }
    cout<<endl;
}