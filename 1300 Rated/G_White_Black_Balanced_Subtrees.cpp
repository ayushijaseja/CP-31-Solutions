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

int dfs(int &validSubtree, vector<vector<int>> &adj, map<int, bool> &visited, int src, string color)
{
    visited[src] = true;
    int sum = 0;
    if (color[src] == 'W')
        sum++;
    else
        sum--;
    for (auto neighbr : adj[src])
        if (!visited[neighbr])
            sum += dfs(validSubtree, adj, visited, neighbr, color);
    if (sum == 0)
        validSubtree++;
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n - 1);
    vin(v);
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int parent = v[i] - 1;
        int child = i + 1;
        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }
    int count = 0;
    map<int, bool> visited;
    int validSubtrees = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(validSubtrees, adj, visited, i, s);
    }
    cout << validSubtrees << endl;
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