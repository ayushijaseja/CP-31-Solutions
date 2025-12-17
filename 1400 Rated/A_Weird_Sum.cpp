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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        vector<int> row(m);
        vin(row);
        v[i] = row;
    }
    map<int, vector<pair<int, int>>> coordi;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            coordi[v[i][j]].push_back({i, j});
        }
    }

    int ans = 0;
    for (auto color : coordi)
    {
        vector<pair<int, int>> c = color.second;
        int sz = c.size();
        for (int i = sz - 1; i >= 0; i--)
        {
            ans += (i - (sz - 1 - i)) * c[i].first;
        }
        sort(c.begin(), c.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });
        for (int i = sz - 1; i >= 0; i--)
        {
            ans += (i - (sz - 1 - i)) * c[i].second;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}