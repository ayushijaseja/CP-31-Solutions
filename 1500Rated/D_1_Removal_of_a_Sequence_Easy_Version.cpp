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

bool condition(int mid, int &x, int &y, int &k)
{
    int heh = mid - 1;
    for (int i = 0; i < x; i++)
        heh -= heh / y;
    return heh + 1 > k;
}

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;

    int l = 1;
    int r = 1e12 + 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (condition(mid, x, y, k))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (r == 1e12 + 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << r << endl;
    }
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