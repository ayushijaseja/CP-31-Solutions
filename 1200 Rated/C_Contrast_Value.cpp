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

    vector<int> vNew;
    vNew.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (vNew.back() == v[i])
            continue;
        else
            vNew.push_back(v[i]);
    }

    int ans = vNew.size();

    for (int i = 0; i + 2 < vNew.size(); i++)
    {
        ans -= (vNew[i] < vNew[i + 1] && vNew[i + 1] < vNew[i + 2]);
        ans -= (vNew[i] > vNew[i + 1] && vNew[i + 1] > vNew[i + 2]);
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