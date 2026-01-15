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
    vector<int> v(n);
    vin(v);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[v[i]]++;
    vector<int> oddFreqSides;
    int sum = 0;
    int sidesUsed = 0;
    for (auto [side, freq] : mp)
    {
        if (freq % 2 == 0)
        {
            sum += freq * side;
            sidesUsed += freq;
        }
        else
        {
            sidesUsed += (freq - 1);
            sum += (freq - 1) * side;
            oddFreqSides.push_back(side);
        }
    }
    sort(oddFreqSides.rbegin(), oddFreqSides.rend());
    int count = oddFreqSides.size();
    // cout << count << endl;
    if (count == 0)
    {
        if (sidesUsed >= 3)
            r(sum) else r(0);
    }
    else if (count == 1)
    {
        if (oddFreqSides[0] < sum)
        {
            if (sidesUsed + 1 >= 3)
                r(sum + oddFreqSides[0]) else r(0)
        }
        else
        {
            if (sidesUsed >= 3)
                r(sum) else r(0)
        }
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int first = oddFreqSides[i];
            int second = (i != count - 1 ? oddFreqSides[i + 1] : 0);
            if (first < sum + second)
            {
                int sideTaken = 1 + (second != 0);
                if (sidesUsed + sideTaken >= 3)
                    r(sum + first + second);
            }
        }
    }
    if (sidesUsed >= 3)
        r(sum) else r(0)
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