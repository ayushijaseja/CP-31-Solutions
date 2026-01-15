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
    if (n == k)
        r(0)
            set<int>
                piles;
    piles.insert(n);
    int t = 0;
    while (!piles.empty())
    {
        t++;
        set<int> np;
        int maxi;
        for (auto pile : piles)
        {
            if (pile < 2)
                continue;
            int p1 = pile / 2;
            int p2 = (pile + 1) / 2;

            if (p1 == k || p2 == k)
                r(t)
                    np.insert(p1);
            np.insert(p2);
            maxi = max({p1, p2, maxi});
        }
        piles = np;
        if (maxi < k)
            break;
    }
    r(-1)
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