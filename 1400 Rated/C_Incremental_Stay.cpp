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
    int sz = 2 * n;
    vector<int> v(sz);
    vin(v);

    vector<int> prefix(sz + 1, 0);
    for (int i = 1; i < sz + 1; i++)
        prefix[i] = prefix[i - 1] + v[i - 1];
    vector<int> alt(sz + 1, 0);
    for (int i = 1; i < sz + 1; i++)
        alt[i] = alt[i - 1] + (i % 2 ? -1 : 1) * v[i - 1];
    int totalSum = prefix[sz];
    for (int i = 0; i < n; i++)
    {
        int k = i + 1;
        int ans = 0;
        ans = (totalSum - prefix[sz - k]) - prefix[k];
        ans += (k % 2 ? 1 : -1) * (alt[sz - k] - alt[k]);
        cout << ans << " ";
    }
    cout << endl;
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