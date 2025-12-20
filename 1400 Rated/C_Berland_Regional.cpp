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
#define lcm(a, b) ((a) / ([](long long x, long long y) {while(y){long long t=y;y=x%y;x=t;}return x; })(a, b) * (b))
#define MSB_POS(x) ((x) ? 63 - __builtin_clzll(x) : -1)
long long modpow(long long a, long long b, long long m)
{
    long long r = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}
const int MOD = 1e9 + 7;
long long fact(long long n)
{
    long long r = 1;
    for (long long i = 1; i <= n; i++)
        r = (r * i) % MOD;
    return r;
}
bool isSet(int n, int i) { return (n & (1 << i)) != 0; }

void solve()
{
    int n;
    cin >> n;
    vector<int> u(n);
    vin(u);
    vector<int> s(n);
    vin(s);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({s[i], u[i]});
    sort(v.begin(), v.end());
    vector<vector<int>> us(n);
    int sum = 0;
    vector<int> ans(n, 0);
    for (auto p : v)
    {
        int u = p.second;
        int s = p.first;
        if (us[u - 1].empty())
            us[u - 1].push_back(s);
        else
            us[u - 1].push_back(us[u - 1].back() + s);
        sum += s;
    }

    for (int uni = 0; uni < n; uni++)
    {
        int stud = us[uni].size();
        if (stud == 0)
            continue;
        for (int teamSize = 1; teamSize <= stud; teamSize++)
        {
            int k = (stud / teamSize) * teamSize;
            if (k == 0)
                continue;

            int remove = stud - k;
            if (remove == 0)
                ans[teamSize - 1] += us[uni].back();
            else
                ans[teamSize - 1] += us[uni].back() - us[uni][remove - 1];
        }
    }

    vout(ans);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}