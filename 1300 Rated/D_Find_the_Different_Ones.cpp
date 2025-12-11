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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        queries[i] = {x, y};
    }

    for (auto [l, r] : queries)
    {
        map<int, int> mp;
        pair<int, int> ans;
        int a = 0;
        for (int i = l - 1; i <= r - 1; i++)
        {
            if (!mp.count(v[i]))
            {
                mp[v[i]] = i;
                if (a == 0)
                    ans.first = i;
                else if (a == 1)
                    ans.second = i;
                a++;
            }
            if (a == 2)
                break;
        }
        // cout << a << endl;
        if (mp.size() == 1)
            cout << -1 << " " << -1 << endl;
        else
            cout << ans.first + 1 << " " << ans.second + 1 << endl;
    }
    cout << endl;

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