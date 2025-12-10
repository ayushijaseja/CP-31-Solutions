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

int search(vector<int> &v, int num)
{
    int n = v.size();
    int l = 0;
    int r = n - 1;
    int mid = l + (r - l) / 2;
    int ans = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] <= num)
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> steps(n);
    vector<int> ques(q);
    vin(steps);
    vin(ques);

    // sort(steps.begin(), steps.end());

    vector<int> prefix;
    prefix.push_back(steps[0]);

    vector<int> order;
    int x = steps[0];
    order.push_back(x);

    for (int i = 1; i < n; i++)
    {
        x = max(x, steps[i]);
        order.push_back(x);
        prefix.push_back(steps[i] + prefix[i - 1]);
    }
    vector<int> ans;

    for (int i = 0; i < q; i++)
    {
        int x = search(order, ques[i]);
        if (x == -1)
            ans.push_back(0);
        else
            ans.push_back(prefix[x]);
    }

    vout(ans);
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