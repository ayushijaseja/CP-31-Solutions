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

int nod(int n)
{
    return floor(log10(n)) + 1;
}
int zeroes(int n)
{
    int count = 0;
    while (n > 0 && n % 10 == 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vin(v);

    vector<int> trailingZeroes(n);
    for (int i = 0; i < n; i++)
        trailingZeroes[i] = zeroes(v[i]);
    int totalDigits = 0;
    for (int i = 0; i < n; i++)
        totalDigits += nod(v[i]);
    int removable = 0;
    sort(trailingZeroes.begin(), trailingZeroes.end());
    reverse(trailingZeroes.begin(), trailingZeroes.end());
    // vout(trailingZeroes);
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            removable += trailingZeroes[i];

    if (totalDigits - removable > m)
        r("Sasha")
            r("Anna")
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