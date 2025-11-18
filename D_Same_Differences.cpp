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

    for (int i = 0.; i < n; i++)
    {
        v[i] = v[i] - i;
    }

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }

    int ans = 0;

    for (auto [y, x] : freq)
    {
        if (x <= 1)
            continue;
        ans += ((x - 1) * (x)) / 2;
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