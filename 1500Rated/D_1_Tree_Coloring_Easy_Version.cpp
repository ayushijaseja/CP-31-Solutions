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
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    vector<int> count(n + 1, 0);
    queue<int> q;
    vector<int> cc(n + 1, 0);

    q.push(1);
    dist[1] = 0;
    count[0] = 1;

    int d = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int nghbr : adjList[u])
        {
            if (dist[nghbr] == -1)
            {
                dist[nghbr] = dist[u] + 1;
                count[dist[nghbr]]++;
                cc[u]++;
                d = max(d, dist[nghbr]);
                q.push(nghbr);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= d; i++)
    {
        ans = max(ans, count[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, 1ll + cc[i]);
    }
    r(ans);
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