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
    vector<int> v(n);
    vin(v);

    int sum = accumulate(v.begin(), v.end(), 0LL);
    vector<int> vNew(n);

    vector<int> freq(n + 1, 0);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
        if (freq[v[i]] >= 2)
            maxi = max(maxi, v[i]);
        vNew[i] = maxi;
    }
    sum += accumulate(vNew.begin(), vNew.end(), 0LL);
    for (int i = 0; i < freq.size(); i++)
        freq[i] = 0;
    maxi = 0;
    for (int i = 0; i < n; i++)
    {
        freq[vNew[i]]++;
        if (freq[vNew[i]] >= 2)
            maxi = max(maxi, vNew[i]);
        vNew[i] = maxi;
    }

    for (int i = 0; i < n; i++)
        sum += vNew[i] * (n - i);

    r(sum)
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