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
    int n, q;

    cin >> n >> q;

    vector<pair<int, int>> v(n, {0, 0});

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    pair<int, int> globalVal = {0, -1};

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i].first;

    for (int it = 1; it <= q; it++)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            int ind, val;
            cin >> ind >> val;

            ind--;

            if (v[ind].second > globalVal.second)
            {
                sum += (val - v[ind].first);
            }
            else
            {

                sum += (val - globalVal.first);
            }

            v[ind].first = val;
            v[ind].second = it;
        }
        else
        {
            int val;

            cin >> val;

            globalVal.first = val;
            globalVal.second = it;

            sum = (long long)(val)*n;
        }

        cout << sum << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
