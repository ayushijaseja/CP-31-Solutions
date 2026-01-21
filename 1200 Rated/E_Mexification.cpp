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

int mexi(vector<int> &v)
{
    int n = v.size();
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
        freq[v[i]]++;
    int mex = n + 1;
    for (int i = 0; i < n + 1; i++)
    {
        if (freq[i] == 0)
        {
            mex = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] > mex || freq[v[i]] > 1)
        {

            v[i] = mex;
        }
    }

    int sum = accumulate(v.begin(), v.end(), 0ll);
    return sum;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vin(v);

    if (k == 0)
    {
        int sum = accumulate(v.begin(), v.end(), 0ll);
        r(sum);
    }

    int sum1 = mexi(v);
    if (k == 1)
        r(sum1);

    int sum2 = mexi(v);
    if (k % 2 == 0)
        r(sum2);

    int sum3 = mexi(v);
    r(sum3);
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