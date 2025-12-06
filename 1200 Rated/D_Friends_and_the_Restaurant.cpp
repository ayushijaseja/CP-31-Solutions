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
    vector<int> x(n);
    vector<int> y(n);
    vin(x);
    vin(y);

    vector<int> diff;

    for (int i = 0; i < n; i++)
        diff.push_back(y[i] - x[i]);

    sort(diff.begin(), diff.end());
    int s = 0;
    int e = n - 1;
    int ans = 0;
    while (diff[s] < 0 && s < e)
    {
        if (diff[s] + diff[e] >= 0)
        {
            ans++;
            e--;
        }
        s++;
    }
    ans += (e - s + 1) / 2;
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