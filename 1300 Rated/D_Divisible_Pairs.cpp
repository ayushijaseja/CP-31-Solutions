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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    vin(v);

    map<pair<int, int>, int> freq;
    for (int i = 0; i < n; i++)
    {
        int a = v[i] % x;
        int b = v[i] % y;
        freq[{a, b}]++;
    }

    int ans = 0;

    for (auto node : freq)
    {
        auto [a, b] = node.first;
        if (a == 0 || a * 2 == x)
            ans += (node.second) * (node.second - 1);
        else
            ans += (node.second) * (freq[{x - a, b}]);
    }

    cout << ans / 2 << endl;
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