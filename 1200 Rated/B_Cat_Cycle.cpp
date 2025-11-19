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
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0)
    {
        cout << ((k % n) ? (k % n) : n) << endl;
        return;
    }
    else
    {
        int changeAfter = n / 2;
        cout << ((((k + (k - 1) / (changeAfter))) % n) ? (((k + (k - 1) / (changeAfter))) % n) : n) << endl;
        return;
    }
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