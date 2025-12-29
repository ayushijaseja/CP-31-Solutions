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
    vector<int> a(n);
    vector<int> b(n);
    vin(a);
    vin(b);

    int currSum = 0;
    int prev = 0;
    int choice = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            if (choice == -1)
            {
                currSum += b[i];
                choice = 1;
            }
            else if (choice == 2)
            {
                currSum += b[i];
                choice = 1;
                prev = b[i];
            }
            else if (choice == 1)
            {
                int x = prev + a[i];
                int y = b[i];
                if (x > y)
                {
                    currSum += a[i];
                    choice = 2;
                    prev = a[i];
                }
                else
                {
                    currSum = currSum - prev + b[i];
                    prev = b[i];
                    if (x == y)
                        choice = -1;
                }
            }
        }
        else if (a[i] > b[i])
        {
            if (choice == -1)
            {
                currSum += a[i];
                choice = 2;
            }
            else if (choice == 1)
            {
                currSum += a[i];
                choice = 2;
                prev = a[i];
            }
            else if (choice == 2)
            {
                int x = prev + b[i];
                int y = a[i];
                if (x > y)
                {
                    currSum += b[i];
                    choice = 1;
                    prev = b[i];
                }
                else
                {
                    currSum = currSum - prev + a[i];
                    prev = a[i];
                    if (x == y)
                        choice = -1;
                }
            }
        }
        else
        {
            currSum += a[i];
            choice = -1;
        }
    }
    // cout << endl;
    r(currSum);
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