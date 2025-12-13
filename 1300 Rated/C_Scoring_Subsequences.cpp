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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);

    for (int i = n - 1; i > 0; i--)
        v[i] = v[i] - v[i - 1] + 1;
    // vout(v);

    vector<int> ans;
    int sz = 1;
    ans.push_back(1);
    int curr = 0;
    v[curr]--;

    // int ind = curr;

    while (sz != n)
    {
        // cout << curr << " " << v[curr] << endl;
        if (v[curr] != 0)
        {
            ans.push_back(ans.back() + 1);
            v[curr]--;
        }
        else
        {
            ans.push_back(ans.back());
            curr++;
            v[curr]--;
        }
        sz++;
    }

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