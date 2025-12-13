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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);

    int currmax = v[0];
    int correction = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < currmax)
            v[i] = currmax;
        else if (v[i] == currmax)
            correction++;
        else
            currmax = v[i];
    }
    // vout(v);
    int ans = 0;
    int prev = v[0];
    int freq = 1;
    for (int i = 1; i < n; i++)
    {
        if (prev == v[i])
            freq++;
        else
        {
            ans += freq - 1;
            freq = 1;
            prev = v[i];
        }
    }
    ans += freq - 1;
    r(ans - correction);
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