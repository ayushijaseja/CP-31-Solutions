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
    vector<int> v(n);
    vin(v);

    sort(v.begin(), v.end());

    map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[v[i]]++;

    vector<int> newV;
    for (auto [x, y] : freq)
        newV.push_back(x);
    int ans = 0;
    int curr = freq[newV[0]];
    int u = newV.size();
    // vout(newV);
    for (int i = 0; i < u; i++)
    {
        // cout << curr << " " << "i=" << i << " ";
        if (curr > freq[newV[i] + 1])
            ans += curr - freq[newV[i] + 1];
        curr = freq[newV[i] + 1];
        if (curr == 0)
            curr = freq[newV[i + 1]];
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