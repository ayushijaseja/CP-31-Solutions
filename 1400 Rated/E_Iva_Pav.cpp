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
bool isSet(int n, int i) { return (n & (1LL << i)) != 0; }
bool compare(const vector<int> &andOP, const vector<int> &kB)
{
    for (int i = 30; i >= 0; i--)
    {
        if (andOP[i] != kB[i])
            return andOP[i] > kB[i];
    }
    return true;
}

bool condition(vector<int> &andOP, int x, vector<int> &kB, vector<vector<int>> &PreC)
{
    for (int i = 0; i < 31; i++)
        if (andOP[i] != PreC[x][i])
            andOP[i] = 0;
    return compare(andOP, kB);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vin(v);
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        queries[i] = {x, y};
    }

    vector<vector<int>> PreC(n, vector<int>(31));
    for (int i = 0; i < n; i++)
    {
        int num = v[i];
        vector<int> bits(31);
        for (int i = 0; i < 31; i++)
            bits[i] = isSet(num, i);
        PreC[i] = bits;
    }

    vector<int> ans;
    for (auto query : queries)
    {
        int l = query.first;
        int k = query.second;
        if (v[l] < k)
        {
            ans.push_back(-1);
            continue;
        }
        vector<int> andOP(31, 0);
        vector<int> kB(31, 0);
        for (int i = 0; i < 31; i++)
            kB[i] = isSet(k, i);
        for (int i = 0; i < 31; i++)
            andOP[i] = isSet(v[l], i);
        int r = 0;
        while (l + r + 1 < n && condition(andOP, l + r + 1, kB, PreC))
            r++;
        ans.push_back(l + r + 1);
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