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

    int a, b, c;
    int i;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            break;
    if (i * i > n)
    {
        r("NO");
    }
    int n1 = n / i;
    int j;
    for (j = i + 1; j * j <= n1; j++)
        if (n1 % j == 0)
            break;
    if (j * j > n1)
    {
        r("NO");
    }
    int n2 = n1 / j;
    a = i;
    b = j;
    c = n2;
    if (n2 == 1 || n2 == a || n2 == b)
        r("NO") else
        {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
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