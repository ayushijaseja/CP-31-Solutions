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

char getchar(char a, char b)
{
    int ai = a - 'a';
    int bi = b - 'a';
    int mn = min(ai, bi);
    int mx = max(ai, bi);
    if (mx + 'a' == 'z' && mn + 'a' == 'a')
        return 'b';
    if (mx + 'a' == 'z' && mn + 'a' != 'a')
        return 'a';
    else
        return mx + 1 + 'a';
}

void solve()
{
    string s;
    cin >> s;
    int len = s.length();
    char prev = s[0];
    // int ans = 0;
    for (int i = 1; i < len; i++)
    {
        if (s[i] == s[i - 1])
        {
            if (i + 1 < len)
            {
                s[i] = getchar(s[i - 1], s[i + 1]);
                // ans++;
            }
            else
            {
                if (i - 2 >= 0)
                    s[i] = s[i - 2];
                else
                    s[i] = (s[i - 1] + 1) % 26 + 1 + 'a';
                // ans++;
            }
        }
    }
    cout << s << endl;
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