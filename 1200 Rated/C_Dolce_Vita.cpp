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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    vin(v);

    sort(v.begin(), v.end());

    if (v[0] > x)
    {
        cout << 0 << endl;
        return;
    }
    int i;
    for (i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
        if (v[i] > x)
            break;
    }
    int idx = i - 1;

    vector<int> days;

    for (int i = 0; i < idx + 1; i++)
    {
        int nod = 1 + (x - v[i]) / (i + 1);
        days.push_back(nod);
    }
    // vout(days);

    int sz = days.size();

    for (int i = 0; i < sz - 1; i++)
    {
        days[i] = days[i] - days[i + 1];
    }
    // vout(days);

    int ans = 0;

    for (int i = 0; i < sz; i++)
    {
        ans += (i + 1) * days[i];
    }
    cout << ans << endl;
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