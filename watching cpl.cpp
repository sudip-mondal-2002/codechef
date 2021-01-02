// بساملہ ہیر رحمن نیر رحیم
// Born to be a GrandMaster
//---------------------------//
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<bitset>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
#include<chrono>
#include<list>
#include<climits>
#include<iomanip>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #define PBDS tree<long long int,null_type,less<long long int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
#define arrsize 100001
#define dpsize 1001
#define vpp vector<PP>
#define vll vector<ll>
#define vcc vector<char>
#define endl "\n"
#define vbb vector<bool>
#define w(t) while(t--)
#define PP pair<ll,ll>
#define test(x) ll t; cin>>t; w(t) x()
#define __lb lower_bound
#define __ub upper_bound
#define szs(x) x.length()
#define szv(x) x.size()
#define INF 1999999996000000010
#define ll long long int
#define takeINP(arr,n) for(long long int i=0;i<n;i++) cin>>arr[i];
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define mem(arr) memset(arr,0,sizeof(arr));
#define MOD 1000000007
#define rsz(x,n) x.resize(n)
#define rsr(x,n) x.reserve(n) 
#define mp(a,b) make_pair(a,b)
#define float long long double
#define pb push_back
#define print(arr,s,e) f(i,s,e) cout<<arr[i]<<" "; cout<<endl;
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define vll vector<ll>
#define triplet pair<ll,pair<ll,ll> >
#define MITR(a,b) map<a,b>::reverse_iterator 
using namespace std;
using namespace chrono;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 <<endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
///---------------Functions---------------------///
ll advceil(ll num,ll den){return (num%den==0?num/den:num/den+1);}
ll lstbt(ll val){ ll msk = val&(val-1); return log2(val^msk);}
ll modmul(ll a,ll b){    a%=MOD; b%=MOD;    ll res = 0;    while(b>0){        if(b&1) res = (res+a)%MOD;        a = (a*2)%MOD;        b/=2;    }    return res;}
ll modexpo(ll a,ll b){    ll res=1;    while(b>0){        if(b&1) res = modmul(res,a);        a = modmul(a,a);        b/=2;    }    return res;}
ll gcd(ll a,ll b){ return a==0?b:gcd(b%a,a); }
vll CALCfactor(ll n){    vll factor(n+2,0);    for(ll i=4;i<=n;i+=2) factor[i]=2;    for(ll j=3;j<=n;j+=2){        if(factor[j]) continue;        for(ll i=2*j;i<=n;i+=j) factor[i]=j;    }    return factor;}
vll CALCprimeNUM(ll n){    vll factor = CALCfactor(n);    vll primeNUM; primeNUM.reserve(n+2);    cf(i,2,n) if(!factor[i]) primeNUM.pb(i);    return primeNUM;}
vll CALCprimeFACTOR(ll n){    vll factor = CALCfactor(n);    vll ans;    while(factor[n]!=0){        ans.pb(factor[n]);        n/=factor[n];    }    if(n>1) ans.pb(n);    return ans;}
vll unique(vll x){    sort(all(x)); set<ll> s;    vll ans; ans.reserve(szv(x));    for(auto elem : x) s.insert(elem);    for(auto elem : s) ans.pb(elem);    return ans;}
pair<vll,vll> getFact(ll n){    vll fact(n+1,1),invfact(n+1,1);    cf(i,1,n) fact[i]=(i*(fact[i-1]))%MOD;    cf(i,1,n) invfact[i]=(modexpo(i,MOD-2)*invfact[i-1])%MOD;    return {fact,invfact};}
void compress(vll &arr,ll n){     map<ll,vll> pos;    cf(i,1,n) pos[arr[i]].pb(i);    ll cnt = 1;    for(auto itr : pos){        for(auto elem : itr.ss) arr[elem]=cnt;        cnt++;    }}
///---------x------------x----------x-----------///

ll dp[4020][4020];
ll pref[4020];

ll Dfn(ll idx,ll taken,ll n,ll k,vll &arr){
    if(taken>=k and (pref[idx]-taken>=k)) return 0;
    else if(idx>=n)  return 1e10;
    else if(dp[idx][taken]!=-1) return dp[idx][taken];

    ///so now two choice again
    ll c1 = Dfn(idx+1,min(taken+arr[idx],pref[idx]-taken),n,k,arr);
    ll c2 = Dfn(idx+1,min(pref[idx]-taken+arr[idx],taken),n,k,arr);
    
    return dp[idx][taken] = 1+min(c1,c2);
}

ll givemedp(vll &arr,ll n,ll k){
    f(i,0,n/2) swap(arr[i],arr[n-i-1]);
    cf(i,0,n+10){
        pref[i]=0;
        cf(j,0,k+10) dp[i][j]=-1;
    }
    cf(i,1,n) pref[i]=pref[i-1]+arr[i-1];
    ll ans = Dfn(0,0,n,k,arr);
    return ans>1e9?-1:ans;
}

void solve(){
    ll n,k; cin>>n>>k;
    vll arr(n,0);
    takeINP(arr,n);
    sort(all(arr));
    if(n==1){
        cout<<"-1"<<endl;
        return;
    }
    cout<<givemedp(arr,n,k)<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" ,stdin);
        freopen("output.txt", "w" ,stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start1 = high_resolution_clock::now();
    // solve();
    test(solve);
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration.count() / 1000.0 << endl;
        cout<<duration.count()/1000.0<<endl;
    #endif
}