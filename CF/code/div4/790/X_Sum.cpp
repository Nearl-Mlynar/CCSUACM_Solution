#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int g[205][205];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int res = 0;
            int k = i - j;
            for (int x = 0; x < n; x++)
            {
                int y = x - k;
                if (0 <= y && y < m)
                {
                    res += g[x][y];
                }
            }

            int s = i + j;
            for (int x = 0; x < n; x++)
            {
                int y = s - x;
                if (0 <= y && y < m)
                {
                    res += g[x][y];
                }
            }

            mx = max(mx, res - g[i][j]);
        }
    }

    cout << mx << endl;
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