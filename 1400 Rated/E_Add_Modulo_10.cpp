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
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);
    for (int i = 0; i < n; i++)
        if (v[i] % 2 != 0)
            v[i] += v[i] % 10;
    // vout(v);
    int zeroes = 0;
    int nonZeroes = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 10 == 0)
            zeroes++;
        else
            nonZeroes++;
        if (zeroes > 0 && nonZeroes > 0)
            r("No");
    }
    // cout << zeroes << " " << nonZeroes << endl;
    if (zeroes == n)
    {
        for (int i = 1; i < n; i++)
        {
            if (v[0] != v[i])
                r("No");
        }
        r("Yes");
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] % 10 == 4)
            v[i] += 18;
        else if (v[i] % 10 == 6)
            v[i] += 6;
        else if (v[i] % 10 == 8)
            v[i] += 14;
    }
    int mn = v[0];
    for (int i = 0; i < n; i++)
        mn = min(mn, v[i]);

    for (int i = 0; i < n; i++)
        v[i] -= mn;
    for (int i = 0; i < n; i++)
        if (v[i] % 20 != 0)
            r("No");
    r("Yes");
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