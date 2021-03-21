#include "bits/stdc++.h"
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define whin(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define nl "\n"
#define all(v) (v).begin(), (v).end()
#define clr(v) memset(v, 0, sizeof(v));
#define sqr(x) ((x) * (x))
#define pt(x)cout<<((x))<<"\n";
typedef int ll;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vectorpairlong;
const long long int inf = 1e18;
const long long int mod = 1e9 + 7;
const long long int MOD = 998244353;


template <typename T>
T power(T a, T b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else
    {
        T res = (power(a, b / 2));
        if (b % 2)
        {
            return (res * res * a);
        }
        else
        {
            return res * res;
        }
    }
}
template <typename T>
T power(T a, T b, T modulo)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else
    {
        T res = (power(a, b / 2, modulo) % modulo);
        if (b % 2)
        {
            return ((((res % modulo) * (res % modulo)) % modulo) * (a % modulo)) % modulo;
        }
        else
        {
            return ((res % modulo) * (res % modulo)) % modulo;
        }
    }
}
template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void factorial(vll &fact, ll n)
{
    fact.resize(n + 1, 1);
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
    }
}
struct HASH
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll modular_inverse(ll a) { return (power<ll>(a, mod - 2, mod)) % mod; }
ll binomialcoeffncr(ll n, ll r, vll &fact)
{
    if (r > n or n < 0 or r < 0)
        return 0LL;
    return (((fact[n] % mod) * (modular_inverse(fact[n - r]) % mod)) % mod * (modular_inverse(fact[r]) % mod)) % mod;
}
ll n;
vector<vi> tree;
vi cc;
vector<unordered_map<ll, ll, HASH>> store;
vi shrinktree;
vector<set<pll>> ifalready;
void read()
{
    cin >> n;
    tree.resize(n + 1);
    cc.resize(n + 1, 0);
    store.resize(n + 1);
    shrinktree.resize(n + 1);
    ifalready.resize(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        ll x;
        cin >> x;
        tree[x].emplace_back(i);
        cc[x]++;
    }
}
void goingedges(ll nd)
{
    shrinktree[nd] = nd;
    for (auto &child : tree[nd])
    {
        goingedges(child);
        if (cc[nd] == 1)
            shrinktree[nd] = shrinktree[child];
    }
}
void dfsontree(ll nd)
{
    for (auto &to : tree[nd])
    {
        ll c = to;
        if (cc[nd] == 1)
            c = shrinktree[nd];
        if (cc[c] == 0)
        {
            store[nd][cc[nd]]++;
            store[c][1]++;
            continue;
        }
        dfsontree(c);
        for (auto &it : store[c])
        {
            store[nd][cc[nd] * 1ll * it.first] += it.second;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    read();
    goingedges(1);
    dfsontree(1);
    whin(q)
    {
        ll nd, w;
        cin >> nd >> w;
        nd = shrinktree[nd];
        auto iterat = ifalready[nd].lower_bound(pll{w, -1});
        if (iterat != ifalready[nd].end() and iterat->first == w)
        {
            pt(iterat->second);
            continue;
        }
        ll p = 0ll;
        for (auto &i : store[nd])
        {
            if (i.first and w % i.first == 0)
            {
                p += (w / i.first) * i.second * 1ll;
            }
        }
        ifalready[nd].insert(pll{w, w - p});
        pt(w - p);
    }
    return 0;
}
