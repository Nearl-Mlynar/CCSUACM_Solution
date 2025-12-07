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

    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(1 << 6, 0));

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int mask = 0; mask < (1 << 6); mask++)
        {
            dp[i][mask] = (dp[i][mask] + dp[i - 1][mask]) % mod;
            dp[i][mask & a[i]] = (dp[i][mask & a[i]] + dp[i - 1][mask]) % mod;
        }
        dp[i][a[i]] = (dp[i][a[i]] + 1) % mod;
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << 6); mask++)
    {
        if (__builtin_popcount(mask) == k)
        {
            ans = (ans + dp[n][mask]) % mod;
        }
    }

    cout << ans << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}