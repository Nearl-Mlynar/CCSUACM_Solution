#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int n, m, q;
i64 g[505][505], sum[505][505];
int dx[] = {0, 1, -1, 0, 0, 2, -2, 1, -1, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1, 0, 0, 1, -1, -1, 1, 2, -2};

void add(int i, int j, i64 v, i64 *mx, int *ansx, int *ansy)
{
    for (int k = 0; k < 13; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m)
        {
            sum[x][y] += v;
            if (sum[x][y] > *mx)
            {
                *mx = sum[x][y];
                *ansx = x, *ansy = y;
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 13; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= m)
                {
                    sum[x][y] += g[i][j];
                }
            }
        }
    }

    i64 mx = LLONG_MIN;
    int ansx = -1, ansy = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (sum[i][j] > mx)
            {
                mx = sum[i][j];
                ansx = i, ansy = j;
            }
        }
    }

    while (q--)
    {
        int x, y, v;
        cin >> x >> y >> v;

        add(x, y, v, &mx, &ansx, &ansy);

        cout << ansx << " " << ansy << endl;
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