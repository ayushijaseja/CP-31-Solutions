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
    vector<int> a(n), b(n);
    vin(a);
    vin(b);

    int ones = 0;
    int zeroes = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            ones++;
        else
            zeroes++;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
            ones++;
        else
            zeroes++;
    }

    if (ones % 2 == 0)
    {
        cout << "Tie" << endl;
        return;
    }
    int i;

    for (i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            break;
    }
    if (i % 2 == 0)
        cout << "Ajisai" << endl;
    else
        cout << "Mai" << endl;
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