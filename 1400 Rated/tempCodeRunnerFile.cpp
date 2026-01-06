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
    
    vector<int> v(2 * n);
    vin(v);

    vector<int> prefix(2 * n);
    prefix[0] = v[0];
    for (int i = 1; i < 2 * n; i++)
        prefix[i] = prefix[i - 1] + v[i];

    vector<int> suffix(2 * n);
    suffix[2 * n - 1] = v[2 * n - 1];
    for (int i = 2 * n - 2; i >= 0; i++)
        suffix[i] = suffix[i + 1] + v[i];

    vector<int> evenNeg(2 * n);
    int sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i % 2 == 0)
            sum += ((-1) * v[i]);
        else
            sum += v[i];
        evenNeg[i] = sum;
    }

    vector<int> oddNeg(2 * n);
    sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i % 2 == 1)
            sum += ((-1) * v[i]);
        else
            sum += v[i];
        oddNeg[i] = sum;
    }

    vector<int> ansV(n);

    for (int i = 0; i < n - 1; i++)
    {
        int ans = 0;
        if (i % 2 == 0)
        {
            ans = suffix[i] - prefix[i];
            ans += evenNeg[2 * n - i - 1] - evenNeg[i];
        }

        else
        {
            ans += suffix[i] - prefix[i];
            ans += oddNeg[2 * n - i - 1] - oddNeg[i];
        }

        ansV[i] = ans;
    }
    ansV[n - 1] = suffix[n - 1] - prefix[n - 1];
    vout(ansV);
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