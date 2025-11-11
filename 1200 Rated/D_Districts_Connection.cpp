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
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = {x, 1 + i};
    }

    sort(v.begin(), v.end());

    int i = 1;
    while (i < n && v[i].first == v[i - 1].first)
        i++;

    // cout << i << endl;

    if (i >= n)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int j = i;
    for (int j = i; j < n; j++)
    {
        cout << v[i - 1].second << " " << v[j].second << endl;
    }

    for (int k = 0; k < i - 1; k++)
    {
        cout << v[k].second << " " << v[i].second << endl;
    }

    return;
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