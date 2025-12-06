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
#define lcm(a, b) ((a) / ([](long long x, long long y) { while(y){ long long t=y; y=x%y; x=t;} return x; })(a, b) * (b))
#define MSB_POS(x) ((x) ? 63 - __builtin_clzll(x) : -1)

int calculateMinOp(string s, int left, int right, int remove)
{
    int ans = 1;
    char c = s[remove];
    while (left <= right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            if (!(s[left] == c || s[right] == c))
                return -1;
            else if (s[left] == c)
            {
                left++;
                ans++;
            }
            else
            {
                right--;
                ans++;
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            int x = calculateMinOp(s, left + 1, right, left);
            int y = calculateMinOp(s, left, right - 1, right);

            if (min(x, y) == -1)
                cout << max(x, y) << endl;
            else
                cout << min(x, y) << endl;
            return;
        }
    }
    cout << 0 << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}