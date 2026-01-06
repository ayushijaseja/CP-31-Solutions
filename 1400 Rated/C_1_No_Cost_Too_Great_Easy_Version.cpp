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

void primeFactors(int n, map<int, int> &mp, int &ans)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
        if (mp[i] > 1)
        {
            ans = 0;
            return;
        }
        while (n % i == 0)
        {
            if (mp[i] > 1)
            {
                ans = 0;
                return;
            }
            n /= i;
        }
    }
    if (n > 1)
    {
        mp[n]++;
        if (mp[n] > 1)
        {
            ans = 0;
            return;
        }
    }
}

void primeFactors2(int n, map<int, int> mp, int &ans)
{
    // cout << "n = " << n << endl;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
        if (mp[i] > 1)
        {
            ans = 0;
            return;
        }
        while (n % i == 0)
        {
            if (mp[i] > 1)
            {
                ans = 0;
                return;
            }
            n /= i;
        }
    }
    if (n > 1)
    {
        mp[n]++;
        if (mp[n] > 1)
        {
            ans = 0;
            return;
        }
    }
    // for (auto ele : mp)
    //     cout << ele.first << " " << ele.second << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vin(a);
    vin(b);

    map<int, int> mp;
    int ans = -1;
    for (int i = 0; i < n; i++)
        primeFactors(a[i], mp, ans);

    if (ans != -1)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        primeFactors2(a[i] + 1, mp, ans);
    if (ans != -1)
    {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
    return;
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