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

    vector<vector<char>> g(n, vector<char>(m, '.'));

    g[0][0] = '/';

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int x = i + dir[k][0], y = j + dir[k][1];

                if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1)
                {
                    if (g[x][y] == '.')
                    {
                        continue;
                    }
                    if (g[x][y] == '/')
                    {
                        g[i][j] = '\\';
                        break;
                    }
                    else
                    {
                        g[i][j] = '/';
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << g[i][j];
        }

        cout << endl;
    }
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