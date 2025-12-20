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
#define lcm(a, b) ((a) / ([](long long x, long long y) { while (y) { long long t = y; y = x % y; x = t; } return x; })(a, b) * (b))
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

const int MOD = 1e9 + 7;

long long fact(long long n)
{
    long long r = 1;
    for (long long i = 1; i <= n; i++)
        r = (r * i) % MOD;
    return r;
}

bool isSet(int n, int i) { return (n & (1 << i)) != 0; }

void solve()
{
    int nB, nG, k;
    cin >> nB >> nG >> k;

    vector<int> boys(k), girls(k);
    vin(boys);
    vin(girls);

    vector<int> freqB(nB), freqG(nG);
    map<int, int> Fboy, Fgirl;

    for (int i = 0; i < k; i++)
    {
        Fboy[boys[i]]++;
        freqB[boys[i] - 1]++;
    }

    for (int i = 0; i < k; i++)
    {
        Fgirl[girls[i]]++;
        freqG[girls[i] - 1]++;
    }

    int c = 0, d = 0;
    for (auto ele : Fboy)
        c += ele.second * (ele.second - 1) / 2;

    for (auto ele : Fgirl)
        d += ele.second * (ele.second - 1) / 2;

    int total = k * (k - 1) / 2;
    r(total - c - d);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
