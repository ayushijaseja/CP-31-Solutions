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
int compare(int x, int y)
{
    int ans = 0;
    while (x > 0 && y > 0)
    {
        if (x % 10 == y % 10)
            ans++;
        x /= 10;
        y /= 10;
    }
    return ans;
}

void solve()
{
    int n, i, j;
    cin >> n >> i >> j;
    vector<int> one(2);
    vector<int> two(6);
    vector<int> three(24);
    one[0] = 12;
    one[1] = 21;
    two[0] = 123;
    two[1] = 132;
    two[2] = 213;
    two[3] = 231;
    two[4] = 312;
    two[5] = 321;
    three[0] = 1234;
    three[1] = 1243;
    three[2] = 1324;
    three[3] = 1342;
    three[4] = 1423;
    three[5] = 1432;
    three[6] = 2134;
    three[7] = 2143;
    three[8] = 2314;
    three[9] = 2341;
    three[10] = 2413;
    three[11] = 2431;
    three[12] = 3124;
    three[13] = 3142;
    three[14] = 3214;
    three[15] = 3241;
    three[16] = 3412;
    three[17] = 3421;
    three[18] = 4123;
    three[19] = 4132;
    three[20] = 4213;
    three[21] = 4231;
    three[22] = 4312;
    three[23] = 4321;
    // cout << two[i - 1] << " " << two[j - 1] << endl;
    if (n == 12)
        cout << compare(one[i - 1], one[j - 1]) << "A" << 2 - compare(one[i - 1], one[j - 1]) << "B" << endl;
    else if (n == 123)
        cout << compare(two[i - 1], two[j - 1]) << "A" << 3 - compare(two[i - 1], two[j - 1]) << "B" << endl;
    else
        cout << compare(three[i - 1], three[j - 1]) << "A" << 4 - compare(three[i - 1], three[j - 1]) << "B" << endl;
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