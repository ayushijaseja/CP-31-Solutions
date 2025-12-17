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
    int n, w;
    cin >> n >> w;
    vector<int> ws(n);
    vin(ws);

    vector<int> bits(21, 0);

    for (int i = 0; i < n; i++)
        bits[MSB_POS(ws[i])]++;
    int tol = 0;
    while (tol < w)
    {
        bool ok = true;
        for (int i = 0; i < 21; i++)
        {
            if (bits[i] <= 0)
                continue;
            int bl = modpow(2, i, 1e9 + 7);
            if (w - tol >= bl)
            {
                tol += bl;
                bits[i]--;
            }
            else
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
    }
    int h = 0;
    for (int i = 0; i < 21; i++)
        h = max(h, bits[i]);
    cout << 1 + h << endl;
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