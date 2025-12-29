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

bool check(vector<int> &ans, int a, int b, int c, int w, int h, int d)
{
    vector<array<int, 3>> perms = {
        {a, b, c}, {a, c, b}, {b, a, c}, {b, c, a}, {c, a, b}, {c, b, a}};

    for (auto &p : perms)
    {
        int x = p[0], y = p[1], z = p[2];
        if (w % x == 0 && h % y == 0 && d % z == 0)
        {
            ans = {x - 1, y - 1, z - 1};
            return true;
        }
    }
    return false;
}

void solve()
{
    int w, h, d;
    int n;
    cin >> w >> h >> d >> n;

    for (int a = 1; a * a * a <= n; a++)
    {
        if (n % a == 0)
        {
            int n1 = n / a;

            for (int b = a; b * b <= n1; b++)
            {
                if (n1 % b == 0)
                {
                    int c = n1 / b;

                    vector<int> ans;
                    if (check(ans, a, b, c, w, h, d))
                    {
                        vout(ans);
                        return;
                    }
                }
            }
        }
    }
    r(-1);
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