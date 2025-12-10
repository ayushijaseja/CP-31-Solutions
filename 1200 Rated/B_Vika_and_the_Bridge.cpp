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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vin(v);

    map<int, int> diff1, diff2;
    map<int, int> prevIdx;

    for (int i = 0; i < n; i++)
    {
        int color = v[i];
        if (!prevIdx.count(color))
            diff1[color] = i;
        else
        {
            int newd = i - prevIdx[color] - 1;
            if (newd > diff1[color])
            {
                diff2[color] = diff1[color];
                diff1[color] = newd;
            }
            else if (newd > diff2[color])
            {
                diff2[color] = newd;
            }
        }
        prevIdx[color] = i;
    }
    for (int i = 0; i < k; i++)
    {
        int color = i + 1;
        int newd = n - prevIdx[color] - 1;
        if (newd > diff1[color])
        {
            diff2[color] = diff1[color];
            diff1[color] = newd;
        }
        else if (newd > diff2[color])
        {
            diff2[color] = newd;
        }
    }
    map<int, int> ans;
    for (int i = 0; i < k; i++)
    {
        int color = i + 1;
        int x = diff1[color] / 2;
        ans[color] = max(diff2[color], x);
    }
    int finalA = 1e9;
    for (int i = 0; i < k; i++)
    {
        int color = i + 1;
        finalA = min(finalA, ans[color]);
    }
    cout << finalA << endl;
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