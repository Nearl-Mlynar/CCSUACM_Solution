#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    i64 res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (a[x] < k)
        {
            cnt++;
            res += a[x];
        }
    }

    cout << cnt << " " << res << endl;
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