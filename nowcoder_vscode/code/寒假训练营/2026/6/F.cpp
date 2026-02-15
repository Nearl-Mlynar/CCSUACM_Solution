#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<i64> g(n * m, LLONG_MAX);
    vector<i64> vis(n * m, 0);
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;

    auto f = [&](i64 x, i64 y)
    {
        return (x - 1) * m + (y - 1);
    };

    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;
        int p = f(x, y);
        g[p] = 0;
        pq.push({0, p});
    }

    for (int i = 0; i < b; i++)
    {
        i64 x, y, t;
        cin >> x >> y >> t;
        vis[f(x, y)] = t;
    }

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != g[u])
        {
            continue;
        }
        int x = u / m + 1;
        int y = u % m + 1;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
            {
                continue;
            }

            int p = f(nx, ny);
            i64 mx = max(d + 1, vis[p]);

            if (mx < g[p])
            {
                g[p] = mx;
                pq.push({mx, p});
            }
        }
    }

    i64 ans = 0;
    for (i64 x : g)
    {
        ans = max(ans, x);
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
