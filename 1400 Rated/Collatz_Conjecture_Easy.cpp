#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    while (n % 2 == 0)
        n /= 2;

    if (n == 1 || n == 3)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
