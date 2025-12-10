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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vin(v);
    vector<int> modulos(m);
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int x = v[i] % m;
        modulos[x]++;
    }
    int ans = 0;
    if (modulos[0] > 0)
        ans++;

    if (m % 2 == 0)
    {
        if (modulos[m / 2] > 0)
            ans++;

        for (int i = 1; i < m / 2; i++)
        {
            int a = modulos[i];
            int b = modulos[m - i];
            if (a == 0 && b == 0)
                continue;

            ans++;
            int extra = max(0LL, abs(a - b) - 1);
            ans += extra;

            modulos[i] = modulos[m - i] = 0;
        }
    }
    else
    {
        for (int i = 1; i <= m / 2; i++)
        {
            int a = modulos[i];
            int b = modulos[m - i];
            if (a == 0 && b == 0)
                continue;

            ans++;
            int extra = max(0LL, abs(a - b) - 1);
            ans += extra;

            modulos[i] = modulos[m - i] = 0;
        }
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