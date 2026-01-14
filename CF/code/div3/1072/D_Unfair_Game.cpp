#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 35;

int pre[N][N];

int init = []()
{
    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < 30; ++j)
        {
            if (i < j)
            {
                pre[i][j] = 0;
            }
            else if (j == 0)
            {
                pre[i][j] = 1;
            }
            else
            {
                pre[i][j] = pre[i - 1][j] + pre[i - 1][j - 1];
            }
        }
    }
    return 0;
}();

void solve()
{
    int n, k;

    cin >> n >> k;

    int res = 0;

    int mx = __lg(n);
    int ans = mx + 1 > k ? 1 : 0;

    for (int i = 0; i < mx; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            ans += i + j <= k ? 0 : pre[i][j - 1];
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}