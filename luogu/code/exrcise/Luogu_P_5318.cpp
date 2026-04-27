#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; i >= b; --i)
#define all(v, l, r, ...) v.begin() + l, v.begin() + r, ##__VA_ARGS__
#define rall(v, l, r, ...) v.rbegin() + l, v.rbegin() + r, ##__VA_ARGS__
#define endl '\n'

const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    return 0;
}();

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> g[n + 2];
    forn(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    forn(i, 1, n)
    {
        sort(g[i].begin(), g[i].end());
    }

    vector<bool> vis(n + 1, false);
    function<void(int)> dfs = [&](int v)
    {
        vis[v] = true;
        cout << v << ' ';
        for (auto &u : g[v])
        {
            if (!vis[u])
            {
                dfs(u);
            }
        }
    };

    auto bfs = [&]() -> void
    {
        queue<int> q;
        vector<bool> vis(n + 1, false);

        q.push(1);
        vis[1] = true;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            cout << x << ' ';

            for (auto &v : g[x])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    };

    dfs(1);
    cout << endl;
    bfs();
    cout << endl;
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}