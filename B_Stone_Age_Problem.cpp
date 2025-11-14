#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vin(a) for (int i = 0; i < (a).size(); i++) cin >> a[i];
#define vout(a) for (int i = 0; i < (a).size(); i++) cout << a[i] << ' '; cout << endl;
#define r(x) { cout << x << '\n'; return; }
#define lcm(a, b) ((a) / ([](long long x, long long y){ while(y){ long long t=y; y=x%y; x=t;} return x; })(a, b) * (b))

void solve() {
    int n , q ;
    cin >> n;
    cin >> q;

    vector<int> v(n);
    vin(v);

    vector<vector<int>> queries(q);

    for(int i = 0 ; i < q ; i++){
        int type ;
        cin >> type;
        queries[i].push_back(type);
        if( type == 1 ){
            int i;
            cin >> i;
            int x ;
            cin >> x;
            queries[i].push_back(i);
            queries[i].push_back(x);
        }
        else {
            int x ;
            cin >> x;
            queries[i].push_back(x);
        }
    }

    for(int i = 0 ; i<n ; i++){

        
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}