#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    // nextZero[i][b] = next index >= i where bit b is 0
    vector<vector<int>> nextZero(n + 1, vector<int>(31, n));
    for (int b = 0; b < 31; b++)
    {
        nextZero[n][b] = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if ((v[i] & (1LL << b)) == 0)
                nextZero[i][b] = i;
            else
                nextZero[i][b] = nextZero[i + 1][b];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, k;
        cin >> l >> k;
        l--;

        if (v[l] < k)
        {
            cout << -1 << " ";
            continue;
        }

        int r = n - 1;
        for (int b = 0; b < 31; b++)
        {
            if (k & (1LL << b))
            {
                r = min(r, nextZero[l][b] - 1);
            }
        }

        cout << r + 1 << " ";
    }
    cout << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
