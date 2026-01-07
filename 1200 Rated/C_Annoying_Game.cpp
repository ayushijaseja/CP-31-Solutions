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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vin(a);
    vin(b);
    if (k % 2 == 0)
    {
        int curr = a[0];
        int maxSum = a[0];
        int start = 0;
        for (int i = 1; i < n; i++)
        {
            if (curr <= 0)
                curr = a[i];
            else
                curr += a[i];
            if (curr > maxSum)
                maxSum = curr;
        }
        r(maxSum);
    }
    else
    {
        if (n == 1)
        {
            r(a[0] + b[0]);
        }

        vector<int> maxLeftSum(n);
        vector<int> maxRightSum(n);

        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += a[i];
            if (curr >= a[i])
                maxLeftSum[i] = curr;
            else
            {
                maxLeftSum[i] = a[i];
                curr = a[i];
            }
        }

        curr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            curr += a[i];
            if (curr >= a[i])
                maxRightSum[i] = curr;
            else
            {
                maxRightSum[i] = a[i];
                curr = a[i];
            }
        }

        int ans = a[0] + b[0] + (maxRightSum[1] > 0 ? maxRightSum[1] : 0);

        for (int i = 1; i < n - 1; i++)
        {
            int sum = a[i] + b[i];
            if (maxLeftSum[i - 1] > 0)
                sum += maxLeftSum[i - 1];
            if (maxRightSum[i + 1] > 0)
                sum += maxRightSum[i + 1];
            ans = max(ans, sum);
        }

        ans = max(ans, a[n - 1] + b[n - 1] + (maxLeftSum[n - 2] > 0 ? maxLeftSum[n - 2] : 0));
        r(ans);
    }
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