#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    string x;
    cin >> x;
    set<ll>s;
    for(auto xx: x)s.insert(xx);

    if(x.size()&1||s.size()==1)cout << -1 << endl;
    else{
        ll one=0, zero=0;
       for(auto xs: x)
         {
             one+=(xs=='1');
             zero+=(xs=='0');
         }
       cout << min(abs((x.size()/2)-zero), abs((x.size()/2)-one)) << endl;
    }
}

int main()
{
    ll test=1;
    cin >> test;
    while(test--)
    {
        solve();
    }
    return 0;
}