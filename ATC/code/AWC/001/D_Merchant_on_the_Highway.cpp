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

    vector<i64> A(n + 1);
    vector<int> B(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i] >> B[i];
    }

    vector<vector<i64>> dp(n + 1, vector<i64>(m + 1, -1e18));

    for (int i = 1; i <= n; ++i)
    {
        int bi = B[i];
        i64 ai = A[i];

        if (bi <= m)
        {
            dp[i][bi] = max(dp[i][bi], ai);
        }

        int left = max(1, i - k);
        for (int l = left; l < i; ++l)
        {
            for (int j = 0; j + bi <= m; ++j)
            {
                if (dp[l][j] == -1e18)
                {
                    continue;
                }
                dp[i][j + bi] = max(dp[i][j + bi], dp[l][j] + ai);
            }
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            ans = max(ans, dp[i][j]);
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