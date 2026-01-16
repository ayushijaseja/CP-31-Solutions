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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    vin(v);

    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        if (v[i] >= n)
            v[i] = n - 1;
    }
    vector<int> prefix(m, 0);
    prefix[0] = v[0];
    for (int i = 1; i < m; i++)
        prefix[i] = prefix[i - 1] + v[i];
    int left = 0;
    int right = m - 1;
    int ans = 0;
    int count = 0;
    // vout(prefix);
    while (left < right)
    {
        // cout << left << " " << right << " " << ans << endl;
        if (v[right] + v[left] >= n)
        {
            int a = (right - left) * v[right];
            int b = prefix[right - 1] - (left != 0 ? prefix[left - 1] : 0);
            // cout << "a: " << a << "b: " << b << endl;
            ans += a + b;
            count += right - left;
            right--;
        }
        else
            left++;
    }

    ans = 2 * (ans - count * n + count);
    r(ans)
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