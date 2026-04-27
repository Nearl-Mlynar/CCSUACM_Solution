#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<i64> c(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }

    vector<i64> q(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        i64 b;
        cin >> a >> b;
        q[a] += b;
    }

    i64 res = 0;
    for (int j = 1; j <= m; j++)
    {
        res += min(c[j], q[j]);
    }

    cout << res << endl;

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