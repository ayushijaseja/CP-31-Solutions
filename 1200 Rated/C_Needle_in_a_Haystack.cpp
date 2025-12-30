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
    string s, t;
    cin >> s >> t;

    map<char, int> a, b;
    for (auto c : s)
        a[c]++;
    for (auto c : t)
        b[c]++;

    for (auto x : a)
    {
        b[x.first] -= x.second;
        if (b[x.first] < 0)
            r("Impossible")
    }

    string r = "";
    for (auto x : b)
        r += string(x.second, x.first);
    sort(r.begin(), r.end());

    string ans = "";
    int i = 0, j = 0;
    while (i < s.size() && j < r.size())
    {
        if (s[i] <= r[j])
            ans += s[i++];
        else
            ans += r[j++];
    }

    while (i < s.size())
        ans += s[i++];
    while (j < r.size())
        ans += r[j++];

    r(ans);
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