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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vin(v);
    // int invalidPairs = 0;
    // vector<int> p(n);
    // for (int i = 0; i < n; i++)
    //     p[i] = v[i] / 2;
    vector<pair<int, int>> breakingIndices;

    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] / 2 >= v[i])
        {
            breakingIndices.push_back({i - 1, i});
        }
    }
    int ans = 0;
    for (int i = 0; i < breakingIndices.size(); i++)
    {
        int len;
        if (i == 0)
            len = breakingIndices[i].first - 0 + 1;
        else
            len = breakingIndices[i].first - breakingIndices[i - 1].second + 1;
        ans += max(0ll, len - (k + 1) + 1);
        if (i == breakingIndices.size() - 1)
        {
            len = n - 1 - breakingIndices[i].second + 1;
            ans += max(0ll, len - (k + 1) + 1);
        }
    }
    if (breakingIndices.empty())
        ans = n - (k + 1) + 1;
    cout << ans << endl;
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