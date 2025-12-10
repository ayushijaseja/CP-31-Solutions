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
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);

    int l = 0;
    int r = n - 1;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(i + 1);
    }

    while (l <= r)
    {
        int mn = *s.begin();
        int mx = *s.rbegin();
        // cout << mn << " " << mx << endl;
        if ((!(v[l] == mn || v[l] == mx) && !(v[r] == mn || v[r] == mx)))
            break;
        if ((v[l] == mn || v[l] == mx))
        {
            s.erase(v[l]);
            l++;
            continue;
        }
        if ((v[r] == mn || v[r] == mx))
        {
            s.erase(v[r]);
            r--;
            continue;
        }
    }
    if (l >= r)
        cout << -1 << endl;
    else
        cout << l + 1 << " " << r + 1 << endl;
    return;
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