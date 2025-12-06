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
    vector<int> a(n), b(n);
    vin(a);
    vin(b);
    int x = 0;

    for (int i = 0; i < n; i++)
        x ^= a[i];
    for (int i = 0; i < n; i++)
        x ^= b[i];

    if (x == 0)
    {
        cout << "Tie" << endl;
        return;
    }

    int bit = MSB_POS(x);
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] ^ b[i]) & (1 << bit))
            idx = i;
    }

    cout << (idx % 2 == 0 ? "Ajisai" : "Mai") << endl;
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