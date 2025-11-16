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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vin(a);
    sort(a.begin(), a.end());

    vector<int> arcs;

    for (int i = 0; i < m; i++)
    {
        int j = (i + 1) % m;
        int arc = (j == 0 ? (a[0] + n) - a[m - 1] - 1 : a[j] - a[i] - 1);
        if (arc > 0)
            arcs.push_back(arc);
    }

    sort(arcs.rbegin(), arcs.rend());

    int saved = 0;
    int days = 0;

    for (int g : arcs)
    {
        int rem = g - 2 * days;
        if (rem <= 0)
            continue;

        if (rem == 1)
        {
            saved += 1;
            days += 1;
        }
        else
        {
            saved += rem - 1;
            days += 2;
        }
    }

    cout << n - saved << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
