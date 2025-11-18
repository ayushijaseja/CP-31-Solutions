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
    string s;
    cin >> n >> s;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int val = i + 1;

        if (s[i] == '0')
        {
            s[i] = '2';
            ans += val;

            int k = 2;
            while (val * k <= n)
            {
                int idx = val * k - 1;

                if (s[idx] == '1')
                    break;

                if (s[idx] == '0')
                {
                    s[idx] = '2';
                    ans += val;
                }

                k++;
            }
        }
        else if (s[i] == '2')
        {
            int k = 2;
            while (val * k <= n)
            {
                int idx = val * k - 1;

                if (s[idx] == '1')
                    break;

                if (s[idx] == '0')
                {
                    s[idx] = '2';
                    ans += val;
                }

                k++;
            }
        }
        else
            continue;
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