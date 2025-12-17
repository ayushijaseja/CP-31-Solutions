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
    vector<vector<int>> caves;
    for (int i = 0; i < n; i++)
    {
        int ki;
        cin >> ki;
        vector<int> monstorQueue(ki);
        vin(monstorQueue);
        caves.push_back(monstorQueue);
    }
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int sz = caves[i].size();
        v[i].second = sz;
        int mx = caves[i][0];
        for (int j = 1; j < sz; j++)
            mx = max(mx, caves[i][j] - j);
        v[i].first = mx;
    }
    sort(v.begin(), v.end());
    vector<int> monsterKilled(n);
    monsterKilled[0] = 0;
    for (int i = 1; i < n; i++)
    {
        monsterKilled[i] += monsterKilled[i - 1] + v[i - 1].second;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, v[i].first - monsterKilled[i]);
    }
    r(ans + 1);
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