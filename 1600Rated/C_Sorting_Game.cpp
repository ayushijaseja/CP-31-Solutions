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
int nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    r = min(r, n - r);
    int x = 1;
    for (int i = 1; i <= r; i++)
    {
        x = x * (n - r + i) / i;
    }
    return x;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string s1 = s;
    sort(s1.begin(), s1.end());
    if (s1 == s)
        r("Bob")
            vector<int>
                ans;
    for (int i = 0; i < n; i++)
        if (s[i] != s1[i])
            ans.push_back(i + 1);
    cout << "Alice" << endl;
    cout << ans.size() << endl;
    vout(ans);
    return;
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