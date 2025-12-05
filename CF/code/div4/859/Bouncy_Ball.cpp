#include <bits/stdc++.h>
using namespace std;
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5;

void solve()
{
    int n, m, x1, y1, x2, y2;
    string s;

    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> s;

    x1--, x2--, y1--, y2--;
    int vis[n][m][4];
    memset(vis, 0, sizeof(vis));
    int d = (s[0] == 'U' ? 1 + (s[1] == 'R' ? 2 : 0) : 0 + (s[1] == 'R' ? 2 : 0));

    int i = x1, j = y1, cnt = 0;

    while (!vis[i][j][d])
    {
        if (i == x2 && j == y2)
        {
            cout << cnt << endl;
            return;
        }

        int a = 0;
        if (d % 2 == 1 && i == 0)
        {
            d -= 1;
            a++;
        }
        if (d % 2 == 0 && i == n - 1)
        {
            d += 1;
            a++;
        }
        if (d >= 2 && j == m - 1)
        {
            d -= 2;
            a++;
        }
        if (d < 2 && j == 0)
        {
            d += 2;
            a++;
        }

        cnt += min(1, a);

        if (vis[i][j][d])
        {
            break;
        }

        vis[i][j][d] = 1;

        if (d & 1)
        {
            i--;
        }
        else
        {
            i++;
        }
        if (d >= 2)
        {
            j++;
        }
        else
        {
            j--;
        }
    }

    cout << -1 << endl;
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