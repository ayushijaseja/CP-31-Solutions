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

    vector<int> freq(n + 2, 0);
    for (int i = 0; i < n; i++)
        freq[v[i]]++;
    vector<int> prefix;
    prefix.push_back(0);
    int mexi = 1;
    while (freq[mexi - 1] != 0)
    {
        int x = prefix.back() + (freq[mexi - 1] - 1);
        prefix.push_back(x);
        mexi++;
    }
    vector<int> suffix(n + 2, 0);
    suffix[n + 1] = 0;
    for (int i = n; i >= 0; i--)
        suffix[i] = suffix[i + 1] + freq[i];
    int maxiMex = prefix.size();
    vector<int> ans(n + 1);
    for (int i = 0; i < maxiMex; i++)
    {
        int l = freq[i];
        int r = prefix[i] + suffix[i];
        ans[l]++;
        if (r + 1 < n + 1)
            ans[r + 1]--;
    }
    for (int i = 1; i < n + 1; i++)
        ans[i] += ans[i - 1];
    vout(ans);
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