#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    i64 res = 0;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        d[i] = x - y;
        res += x;
    }

    sort(d.rbegin(), d.rend());

    cout << res - accumulate(d.begin(), d.begin() + k, 0LL) << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}