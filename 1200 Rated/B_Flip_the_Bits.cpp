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
    string a;
    string b;
    cin >> a;
    cin >> b;

    vector<int> balance(n, -1);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
            count++;
        else
            count--;
        if (count == 0)
            balance[i] = 0;
    }

    bool flipped = false;

    for (int i = n - 1; i >= 0; i--)
    {
        if (flipped)
        {
            if (a[i] == b[i])
            {
                if (balance[i] == 0)
                    flipped = false;
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        else
        {
            if (a[i] != b[i])
            {
                if (balance[i] == 0)
                    flipped = true;
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
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