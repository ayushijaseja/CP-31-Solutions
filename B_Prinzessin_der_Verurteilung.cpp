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
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, bool> mp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            mp[string(1, s[0])] = true;
        else if (i == 1)
        {
            mp[string(1, s[1])] = true;
            mp[s.substr(0, 2)] = true;
        }
        else
        {
            mp[string(1, s[i])] = true;
            mp[s.substr(i - 1, 2)] = true;
            mp[s.substr(i - 2, 3)] = true;
        }
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (mp.count(string(1, c)))
            continue;
        else
        {
            cout << c << endl;
            return;
        }
    }

    string s2;
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (char c1 = 'a'; c1 <= 'z'; c1++)
        {
            string s = string(1, c) + c1;
            if (!mp.count(s))
            {
                cout << s << endl;
                return;
            }
        }
    }
    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        string s = string(1, c1);
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {
            string s1 = s + c2;
            for (char c3 = 'a'; c3 <= 'z'; c3++)
            {
                string s2 = s1 + c3;
                if (!mp.count(s2))
                {
                    cout << s2 << endl;
                    return;
                }
            }
        }
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