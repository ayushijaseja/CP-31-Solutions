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
#define lcm(a, b) ((a) / ([](long long x, long long y) { while(y){ long long t=y; y=x%y; x=t;} return x; })(a, b) * (b))
#define MSB_POS(x) ((x) ? 63 - __builtin_clzll(x) : -1)

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    int sum = accumulate(v.begin(), v.end(), 0LL);

    if (sum == s)
    {
        cout << 0 << "\n";
        return;
    }
    if (sum < s)
    {
        cout << -1 << "\n";
        return;
    }

    unordered_map<int, int> mp;
    mp[0] = -1;

    int k = 0, len = -1;

    for (int i = 0; i < n; i++)
    {
        k += v[i];

        if (mp.count(k - s))
            len = max(len, i - mp[k - s]);

        if (!mp.count(k))
            mp[k] = i;
    }

    // if (len == -1) co ut << -1 << endl;
    cout << n - len << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}