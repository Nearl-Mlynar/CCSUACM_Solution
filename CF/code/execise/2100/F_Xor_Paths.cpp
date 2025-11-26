#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int g[25][25];
int mid, ans;
map<int, int> v[20][20];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    mid = (n + m - 2) / 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    auto dfs1 = [&](auto &&dfs1, int x, int y, int res, int cnt)
    {
        res ^= g[x][y];
        if (cnt == mid)
        {
            v[x][y][res]++;
            return;
        }

        if (x + 1 < n)
        {
            dfs1(dfs1, x + 1, y, res, cnt + 1);
        }
        if (y + 1 < m)
        {
            dfs1(dfs1, x, y + 1, res, cnt + 1);
        }
    };

    auto dfs2 = [&](auto &&dfs2, int x, int y, int res, int cnt)
    {
        if(cnt == n + m - 2 - mid)
        {
            if(v[x][y].count(k ^ res))
            {
                ans += v[x][y][k ^ res];
            }

            return;
        }

        if (x > 0)
        {
            dfs2(dfs2, x - 1, y, res ^ g[x][y], cnt + 1);
        }
        if (y > 0)
        {
            dfs2(dfs2, x, y - 1, res ^ g[x][y], cnt + 1);
        }
    };

    dfs1(dfs1, 0, 0, 0, 0);
    dfs2(dfs2, n - 1, m - 1, 0, 0);

    cout << ans << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}