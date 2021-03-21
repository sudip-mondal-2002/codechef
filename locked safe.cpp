#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define N 1000005
#define sz(s) (int)s.size()
#define lodu_sala                          \
    rep(i, 1, n + 1) scanf("%lld", &v[i]); \
    stack<pair<ll, ll>> dq;                \
    daam[1] = 0;                           \
    arr[1] = (v[1] == 0) ? 1 : 0;          \
    if (v[1] == 0)                         \
        dq.push({1, 1});                   \
    else                                   \
        dq.push({1, 0});

int n;
vector<ll> v(N);
ll arr[N];
ll daam[N];
#define egd                                   \
    stack<ll> dq;                             \
    papa[1] = 0;                              \
    dq.push(1);                               \
    for (int i = 2; i <= n; i++)              \
    {                                         \
        papa[i] = 0;                          \
        while (sz(dq) and v[dq.top()] < v[i]) \
            dq.pop();                         \
        if (sz(dq))                           \
            papa[i] = dq.top();               \
        dq.push(i);                           \
    }
bool bot(ll j, ll k);
ll papa[N];

void f()
{
    egd
}
#define lund                      \
    if (sz(dq))                   \
    {                             \
        if (dq.top().second == 1) \
        {                         \
            dq.pop();             \
            dq.push({res, 1});    \
            if (i != res)         \
                dq.push({i, 0});  \
        }                         \
        else                      \
        {                         \
            dq.push({res, 1});    \
            if (i != res)         \
                dq.push({i, 0});  \
        }                         \
    }                             \
    else                          \
    {
#define hudd                            \
    else if (!sz(dq))                   \
    {                                   \
        dq.push({roast - 1, x.second}); \
        if (x.second)                   \
            tot += roast - 1;           \
    }                                   \
    if (res == roast - 1)               \
    {                                   \
        arr[i] = arr[i - 1] + tot;      \
        if (dq.top().second == 0)       \
            dq.pop();                   \
        dq.push({i, 0});                \
        continue;                       \
    }
#define tang                                       \
    while (sz(dq) and dq.top().first >= roast)     \
    {                                              \
        x = dq.top();                              \
        dq.pop();                                  \
        if (x.second == 1)                         \
        {                                          \
            if (sz(dq))                            \
                tot -= x.first - dq.top().first;   \
            else                                   \
                tot -= x.first;                    \
        }                                          \
    }                                              \
    if (sz(dq) and dq.top().first < roast - 1)     \
    {                                              \
        if (dq.top().second == 0)                  \
            tot += roast - 1 - dq.top().first;     \
        dq.push({roast - 1, dq.top().second ^ 1}); \
    }
#define binary_s                            \
    ll lo = roast, hi = i, res = roast - 1; \
    while (lo <= hi)                        \
    {                                       \
        ll mid = lo + hi;                   \
        mid /= 2;                           \
        if (daam[mid] >= v[i])              \
        {                                   \
            res = mid;                      \
            lo = mid + 1;                   \
        }                                   \
        else                                \
            hi = mid - 1;                   \
    }
#define fs ll tot = (dq.top().second == 1);
#define df                                         \
    ll mn = i, j;                                  \
    daam[i] = 0;                                   \
    ll ans = 0;                                    \
    for (int k = 0; k < 60; k++)                   \
    {                                              \
        j = i - 1;                                 \
        while ((bot(j, k) != bot(i, k)) and j > 0) \
        {                                          \
            daam[j] += (1LL << k);                 \
            j--;                                   \
        }                                          \
        mn = min(mn, j + 1);                       \
    } //p1(tot);
#define lnsdvlldbvlbl                            \
    while (sz(dq) and dq.top().first >= mn)      \
    {                                            \
        x = dq.top();                            \
        dq.pop();                                \
        if (x.second == 1)                       \
        {                                        \
            if (sz(dq))                          \
                tot -= x.first - dq.top().first; \
            else                                 \
                tot -= x.first;                  \
        }                                        \
    }                                            \
    if (sz(dq) and dq.top().first < (mn - 1))    \
    {                                            \
        if (dq.top().second == 0)                \
            tot += mn - 1 - dq.top().first;
vector<ll> t(N);
#define inshaallah                          \
    dq.push({mn - 1, dq.top().second ^ 1}); \
    }                                       \
    else if (!sz(dq))                       \
    {                                       \
        dq.push({mn - 1, x.second});        \
        if (x.second)                       \
            tot += mn - 1;                  \
    }
#define fghj                             \
    ll mx = -1, o = v[i], a = v[i];      \
    for (int j = i; j >= mn; j--)        \
    {                                    \
        mx = max(mx, v[j]);              \
        o |= v[j];                       \
        a &= v[j];                       \
        if ((o ^ a) >= mx)               \
            t[j] = 1;                    \
        else                             \
            t[j] = 0;                    \
    }                                    \
    ll idx = mn;                         \
    while (idx <= i and t[idx] == t[mn]) \
    {                                    \
        idx++;                           \
    }
#define uio                                  \
    if (sz(dq) and dq.top().second == t[mn]) \
    {                                        \
        dq.pop();                            \
        dq.push({idx, t[mn]});               \
    }                                        \
    else                                     \
        dq.push({idx, t[mn]});               \
    if (t[mn])                               \
        tot += idx - mn + 1;                 \
    idx++;                                   \
    while (idx <= i)                         \
    {                                        \
        ll cur = idx;
#define polo                              \
    while (cur <= i and t[cur] == t[idx]) \
        cur++;                            \
    dq.push({cur - 1, t[idx]});           \
    if (t[idx])                           \
        tot += cur - idx;                 \
    idx = cur;                            \
    }                                     \
    arr[i] = arr[i - 1] + tot;            \
    continue;
#define choo             \
    dq.push({res, 1});   \
    if (i != res)        \
        dq.push({i, 0}); \
    }                    \
    tot += res - roast + 1;
void solve()
{
}

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        scanf("%d", &n);
        lodu_sala
            fs

            f();

        rep(i, 2, n + 1)
        {
            df
                ll roast = papa[i];
            roast++;
            if (roast >= mn)
            {
                pair<ll, ll> x;
                lnsdvlldbvlbl
                    inshaallah
                        fghj
                            idx--;
                uio
                    polo
            }
            if (roast < mn)
            {
                binary_s
                    pair<ll, ll>
                        x;
                tang
                    hudd
                        lund
                            choo
            }
            arr[i] = arr[i - 1] + tot;
        }
        printf("%lld\n", arr[n]);
    }
    return 0;
}
bool bot(ll j, ll k)
{
    return ((v[j] & (1LL << k)));
}
