#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<bool> dp1(1 << 13, false);
    dp1[0] = true;

    for (int i = 0; i < n; i++)
    {
        vector<bool> dp2(1 << 13, false);
        for (int x = 0; x < 1 << 13; x++)
        {
            if (!dp1[x])
            {
                continue;
            }
            dp2[max(0, x - a[i])] = true;
            dp2[x ^ b[i]] = true;
        }
        dp1 = move(dp2);
    }

    int ans = 0;
    for (int x = 0; x < 1 << 13; x++)
    {
        if (dp1[x])
        {
            ans = max(ans, x);
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