#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, x;
    cin >> n >> x;

    i64 res = 0, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        i64 a, b, c;
        cin >> a >> b >> c;
        mx = max(a * b - c, mx);
        res += a * (b - 1);
    }

    if (mx <= 0 && res < x)
    {
        cout << -1 << endl;
        return;
    }

    cout << (x <= res ? 0 : (x - res + mx - 1) / mx) << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}