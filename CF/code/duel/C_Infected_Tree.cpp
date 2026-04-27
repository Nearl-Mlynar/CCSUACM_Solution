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

vector<int> g[N];
int sz[N];

int dfs_cnt(int u, int fa)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == fa)
        {
            continue;
        }
        sz[u] += dfs_cnt(v, u);
    }
    return sz[u];
}

int dfs_ans(int u, int fa)
{
    vector<int> a;
    for (int v : g[u])
    {
        if (v != fa)
        {
            a.push_back(v);
        }
    }

    if (a.empty())
    {
        return 0;
    }

    if (a.size() == 1)
    {
        return sz[a[0]] - 1;
    }

    return max(sz[a[0]] - 1 + dfs_ans(a[1], u), sz[a[1]] - 1 + dfs_ans(a[0], u));
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        sz[i] = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_cnt(1, -1);
    cout << dfs_ans(1, -1) << endl;
    return;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}