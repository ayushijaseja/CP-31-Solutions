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

void calculatePrimePower(int x, map<int, int> &mp)
{
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1)
        mp[x]++;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);

    map<int, int> powers;
    for (int i = 0; i < n; i++)
        calculatePrimePower(v[i], powers);
    for (auto [pf, power] : powers)
        if (power % n != 0)
            r("NO");
    r("YES");
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