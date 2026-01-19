#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre(n);
    vector<int> a(1 << n);

    for (int i = 0; i < 1 << n; i++)
    {
        cin >> a[i];
        pre[0].push_back(a[i]);
    }

    for (int i = 1; i < n; i++)
    {
        pre[i].resize(1 << (n - i));
        for (int j = 0; j < 1 << (n - i); j++)
        {
            pre[i][j] = pre[i - 1][j * 2] ^ pre[i - 1][j * 2 + 1];
        }
    }

    while (q--)
    {
        int idx, c;
        cin >> idx >> c;
        idx--;

        int res = c, ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (res < pre[i][idx ^ 1] || (res == pre[i][idx ^ 1] && (idx & 1)))
            {
                ans += (1 << i);
            }

            res ^= pre[i][idx ^ 1];
            idx >>= 1;
        }

        cout << ans << endl;
    }

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