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
    string s;
    cin >> s;
    bool is_palindrome = 1;
    int cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        cnt0 += s[i] == '0';
    }
    if (cnt0 == 1)
    {
        cout << "BOB\n";
        return;
    }
    if (cnt0 % 2)
    {
        cout << "ALICE\n";
        return;
    }
    cout << "BOB\n";
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