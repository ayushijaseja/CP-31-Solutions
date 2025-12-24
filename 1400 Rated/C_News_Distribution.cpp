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

int findParent(vector<int> &parent, int x)
{
    return (parent[x] == x) ? x : parent[x] = findParent(parent, parent[x]);
}
void unionBySize(int u, int v, vector<int> &parent, vector<int> &size)
{
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    if (pu == pv)
        return;
    if (size[pu] < size[pv])
    {
        parent[pu] = pv;
        size[pv] += size[pu];
    }
    else
    {
        parent[pv] = pu;
        size[pu] += size[pv];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> size(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i < n + 1; i++)
    {
        size[i] = 1;
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int ki;
        cin >> ki;
        vector<int> x(ki);
        vin(x);
        for (int i = 1; i < ki; i++)
            unionBySize(x[i - 1], x[i], parent, size);
    }
    for (int i = 1; i < n + 1; i++)
        cout << size[findParent(parent, i)] << " ";
    cout << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}