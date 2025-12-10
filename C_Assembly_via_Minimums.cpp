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
    int sz = n * (n - 1) / 2;
    vector<int> v(sz);
    vin(v);

    sort(v.begin(), v.end());

    vector<int> ans;
    int round = n;

    for (int i = 0; i < sz; i = i + round)
    {
        // cout << i << " ";
        ans.push_back(v[i]);
        round--;
        if (round == 0)
            break;
    }
    // cout << endl;
    ans.push_back(1e9);
    vout(ans);
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