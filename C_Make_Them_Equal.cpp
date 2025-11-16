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
    char c;
    cin >> c;
    string s;
    cin >> s;

    bool already = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
            already = false;
    }

    if (already)
    {
        cout << "0" << endl;
        return;
    }

    for (int i = 2; i <= n; i++)
    {
        bool canOne = true;
        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] != c)
            {
                canOne = false;
                break;
            }
        }
        if (canOne)
        {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }

    cout << 2 << endl;
    cout << n << " " << n - 1 << endl;
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
