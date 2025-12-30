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
    int op = 0;
    if (v[0] > v[1])
    {
        op += v[0] - v[1];
        v[0] = v[1];
    }

    if (n % 2 == 1 && v[n - 1] > v[n - 2])
    {
        op += v[n - 1] - v[n - 2];
        v[n - 1] = v[n - 2];
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            int x = min(v[i - 1], v[i + 1]);
            if (v[i] > x)
            {
                op += v[i] - x;
                v[i] = x;
            }
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (i % 2 == 1)
        {
            int x = v[i - 1] + v[i + 1];
            int y = v[i];
            if (y < x)
            {
                int d = x - y;
                v[i + 1] -= d;
                op += d;
            }
        }
    }
    // vout(v);

    r(op)
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