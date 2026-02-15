#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 5e5 + 5;

struct DSU
{
    vector<int> fa, sz;
    int d;
    i64 res = 0;

    DSU(int n, int dp) : d(dp)
    {
        fa.resize(n + 1);
        sz.assign(n + 1, 0);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void add(int x)
    {
        fa[x] = x;
        sz[x] = 1;
        if (sz[x] >= d)
        {
            res++;
        }
    }

    void unite(int a, int b)
    {
        int fx = find(a);
        int fy = find(b);
        if (fx == fy)
        {
            return;
        }
        if (sz[fx] < sz[fy])
        {
            swap(fx, fy);
        }

        if (sz[fx] >= d)
        {
            res--;
        }
        if (sz[fy] >= d)
        {
            res--;
        }

        fa[fy] = fx;
        sz[fx] += sz[fy];

        if (sz[fx] >= d)
        {
            res++;
        }
    }
};

void solve()
{
    int n, m, x, d;
    cin >> n >> m >> x >> d;

    vector<i64> h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<i64> H(x + 1);
    for (int i = 1; i <= x; i++)
    {
        cin >> H[i];
    }

    vector<pair<i64, int>> c;
    c.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        c.push_back({h[i], i});
    }
    sort(c.begin(), c.end(), greater<>());

    vector<int> vis(n + 1, 0);
    DSU dsu(n, d);
    vector<i64> ans(x + 1);
    int k = 0;

    for (int i = x; i >= 1; i--)
    {
        while (k < n && c[k].first > H[i])
        {
            int u = c[k].second;
            vis[u] = 1;
            dsu.add(u);
            for (int v : g[u])
            {
                if (vis[v])
                {
                    dsu.unite(u, v);
                }
            }
            k++;
        }
        ans[i] = dsu.res;
    }

    for (int i = 1; i <= x; i++)
    {
        cout << ans[i] << endl;
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
