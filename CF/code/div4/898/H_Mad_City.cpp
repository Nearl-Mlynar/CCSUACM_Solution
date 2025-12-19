#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 200005;

vector<int> g[N];
vector<bool> vis(N);

int goal = -1;

bool dfs1(int u, int p)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (v != p && vis[v])
        {
            goal = v;
            return true;
        }
        else if (v != p && !vis[v])
        {
            if (dfs1(v, u))
            {
                return true;
            }
        }
    }
    return false;
}

int dfs2(int u)
{
    vis[u] = true;
    int h = N;
    for (auto v : g[u])
    {
        if (v == goal)
        {
            return 1;
        }
        if (!vis[v])
        {
            h = min(dfs2(v) + 1, h);
        }
    }
    return h;
}

void clear()
{
    for (int i = 1; i < N; i++)
    {
        g[i].clear();
        vis[i] = false;
    }
}

void solve()
{
    clear();

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(b, -1);
    vis.assign(n + 1, false);

    int dM = N, dV = 0;
    if (goal == a)
    {
        dM = 0;
    }
    else
    {
        dM = dfs2(a);
    }

    vis.assign(n + 1, false);

    if (goal == b)
    {
        dV = 0;
    }
    else
    {
        dV = dfs2(b);
    }

    if (dV < dM)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

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