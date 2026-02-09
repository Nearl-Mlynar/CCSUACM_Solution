#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    int mx = -1, ans = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x >= l && x <= r && mx < x)
        {
            mx = x;
            ans = i + 1;
        }
    }

    cout << ans << endl;
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