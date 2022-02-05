#include<bits/stdc++.h>
using namespace std;
class account
{
    int balance;
    static int roi;
    public:
    static int roi2;
    void set(int bal)
    {
        balance=bal;
    }
    void sho()
    {
        cout<<balance<<" "<<roi<<endl;
    }
};
int account::roi2=5;
int account::roi=4;
int main()
{
    account a,b;
    a.set(100);
    a.sho();
    cout<<account::roi2<<" ";
    account::roi2=10;
    cout<<a.roi2<<" ";
}