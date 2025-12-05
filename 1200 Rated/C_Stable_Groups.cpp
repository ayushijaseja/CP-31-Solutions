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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> level(n);
    vin(level);

    sort(level.begin(), level.end());
    int split = 1;

    vector<int> differences;

    for (int i = 1; i < n; i++)
    {
        int diff = level[i] - level[i - 1];
        if (diff > x)
            differences.push_back(diff);
    }

    sort(differences.begin(), differences.end());
    // vout(differences);

    int groups = differences.size();
    // cout << groups << endl;
    int recovery = 0;
    for (int i = 0; i < groups; i++)
    {
        int req;
        if (differences[i] % x != 0)
            req = differences[i] / x;
        else
            req = differences[i] / x - 1;
        if (k - req >= 0)
        {
            k -= req;
            recovery++;
        }
        else
            break;
    }
    // cout << recovery << endl;

    int ans = groups + 1 - recovery;
    cout << ans << endl;
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