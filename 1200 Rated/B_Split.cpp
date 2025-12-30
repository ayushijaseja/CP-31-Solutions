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
    vector<int> v(2 * n);
    vin(v);
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++)
        mp[v[i]]++;
    int odds = 0;
    int eves1 = 0;
    int eves0 = 0;
    for (auto node : mp)
    {
        int num = node.first;
        int freq = node.second;
        // cout << num << " " << freq << endl;
        if (freq % 2 == 1)
            odds++;
        else
        {
            int x = freq / 2;
            if (x % 2 == 0)
                eves0++;
            else
                eves1++;
        }
    }
    // cout << endl;
    // cout << odds << " " << eves1 << " " << eves0 << endl;
    int ans = odds + 2 * eves1 + 2 * eves0;
    if ((eves0 & 1) && odds == 0)
        ans -= 2;
    r(ans)
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