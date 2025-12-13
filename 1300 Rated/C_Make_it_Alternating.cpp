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
const int MOD = 998244353;
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

    int len = s.length();
    char prev = s[0];
    // vector<int> v;
    int currfreq = 1;
    int k = 0;
    int nof = 0;
    int ways = 1;
    for (int i = 1; i < len; i++)
    {
        if (prev == s[i])
            currfreq++;
        else
        {
            if (currfreq != 1)
            {
                nof += currfreq - 1;
                ways = ways * fact(currfreq) % MOD;
            }
            prev = s[i];
            currfreq = 1;
        }
    }
    if (currfreq != 1)
    {
        nof += currfreq - 1;
        ways = ways * fact(currfreq) % MOD;
    }
    cout << nof << " " << ways % MOD << endl;
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