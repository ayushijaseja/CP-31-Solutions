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
    int x, y;
    cin >> x >> y;
    int a = 0;
    int orig = x;
    while (x % 2 == 0)
    {
        a++;
        x /= 2;
    }
    int b = 0;
    while (x % 5 == 0)
    {
        b++;
        x /= 5;
    }
    int k = 1;
    while (a < b && k * 2 <= y)
    {
        k *= 2;
        a++;
    }
    while (b < a && k * 5 <= y)
    {
        k *= 5;
        b++;
    }
    while (k * 10 <= y)
    {
        k *= 10;
    }
    k *= (y / k);
    if (k == 1)
        cout << orig * y << endl;
    else
        cout << orig * k << endl;
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