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

    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            g[i][j] = s[j] - '0';
    }

    long long ans = 0;

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {

            int a = g[i][j];
            int b = g[j][n - 1 - i];
            int c = g[n - 1 - i][n - 1 - j];
            int d = g[n - 1 - j][i];

            int sum = a + b + c + d;
            ans += min(sum, 4 - sum);
        }
    }

    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
