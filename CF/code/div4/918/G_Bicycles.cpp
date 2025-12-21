#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
const int64_t inf = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n];
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<int> s(n);
    for (int &i : s)
    {
        cin >> i;
    }

    vector<vector<int64_t>> dist(n, vector<int64_t>(1001, inf));
    vector<vector<bool>> vis(n, vector<bool>(1001, false));

    dist[0][s[0]] = 0;
    priority_queue<array<int64_t, 3>> q;
    q.push({0, 0, s[0]});

    while (!q.empty())
    {
        int u = q.top()[1], k = q.top()[2];
        q.pop();

        if (vis[u][k] || dist[u][k] == inf)
        {
            continue;
        }

        vis[u][k] = true;

        for (auto &[v, w] : g[u])
        {
            int mm = min(s[v], k);
            if (dist[v][mm] > dist[u][k] + 1LL * w * k)
            {
                dist[v][mm] = dist[u][k] + 1LL * w * k;
                q.push({-dist[v][mm], v, mm});
            }
        }
    }

    int64_t res = inf;
    // 到达终点的摩擦系数不同,时间不同
    for (int k = 1; k <= 1000; k++)
    {
        res = min(res, dist[n - 1][k]);
    }

    cout << res << endl;
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