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
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            x++;
        else
            x--;
    }
    if (x != 0)
        r(-1);
    vector<int> v(n, 0);
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            v[i] = 1;
            y++;
        }
        else if (s[i] == ')' && y > 0)
        {
            y--;
            v[i] = 1;
        }
        // cout << y << " ";
    }
    // cout << endl;
    if (y == 0)
    {
        cout << 1 << endl;
        vout(v);
        return;
    }
    int z = 0;
    vector<int> v1(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            v1[i] = 1;
            z++;
        }
        else if (s[i] == '(' && z > 0)
        {
            z--;
            v1[i] = 1;
        }
        // cout << y << " ";
    }
    // cout << endl;
    if (z == 0)
    {
        cout << 1 << endl;
        vout(v1);
        return;
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] == 0)
                v[i] = 2;
            else if (s[i] == '(' && y > 0)
            {
                y--;
                v[i] = 2;
            }
        }
    }
    set<int> unique;
    for (int i = 0; i < n; i++)
        if (!unique.count(v[i]))
            unique.insert(v[i]);
    if (unique.size() == 1)
    {
        for (int i = 0; i < n; i++)
            v[i] = 1;
    }
    cout << unique.size() << endl;
    vout(v);
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