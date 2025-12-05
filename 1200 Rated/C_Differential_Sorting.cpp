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

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vin(v);

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    bool ok = true;
    for (int i = 1; i < n; i++)
        if (v[i] < v[i - 1])
            ok = false;

    if (ok)
    {
        cout << 0 << endl;
        return;
    }

    if (v[n - 1] < 0)
    {
        cout << -1 << endl;
        return;
    }

    if (v[n - 2] > v[n - 1])
    {
        cout << -1 << endl;
        return;
    }

    cout << n - 2 << endl;
    for (int i = 0; i < n - 2; i++)
        cout << i + 1 << " " << n - 1 << " " << n << endl;
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
