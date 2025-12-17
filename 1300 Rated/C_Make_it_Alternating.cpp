#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vin(a)                           \
    for (int i = 0; i < (a).size(); i++) \
        cin >> a[i];
#define vout(a)                          \
    for (int i = 0; i < (a).size(); i++) \
        cout << a[i] << ' ';             \
    cout << endl;
#define r(x)               \
    {                      \
        cout << x << '\n'; \
        return;            \
    }
#define lcm(a, b) ((a) / ([](long long x, long long y) {while(y){long long t=y;y=x%y;x=t;}return x; })(a, b) * (b))
#define MSB_POS(x) ((x) ? 63 - __builtin_clzll(x) : -1)
long long modpow(long long a, long long b, long long m)
{
    long long r = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}
const int MOD = 998244353;
long long fact(long long n)
{
    long long r = 1;
    for (long long i = 1; i <= n; i++)
        r = (r * i) % MOD;
    return r;
}

void solve()
{
    string s;
    cin >> s;
    int freq = 1;
    char prev = s[0];
    int len = s.length();
    int nop = 0;
    int ways = 1;
    for (int i = 1; i < len; i++)
    {
        if (s[i] == prev)
            freq++;
        else
        {
            prev = s[i];
            nop += freq - 1;
            ways *= (freq);
            ways %= MOD;
            freq = 1;
        }
    }
    nop += freq - 1;
    ways *= (freq);
    ways %= MOD;
    // cout << " nop : " << nop << " ways : " << ways << endl;
    cout << nop << " " << ((ways) * (fact(nop))) % MOD << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}