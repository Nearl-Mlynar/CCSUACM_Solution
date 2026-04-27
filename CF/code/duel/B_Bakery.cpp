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
const i64 N = 1e5 + 7;
const i64 INF = 1e18;

vector<pair<int, i64>> g[N];
i64 dis[N];
bool vis[N];

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    forn(i, 1, N)
    {
        dis[i] = INF;
        vis[i] = false;
    }
    return 0;
}();

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    forn(i, 1, m)
    {
        int u, v;
        i64 l;
        cin >> u >> v >> l;
        g[u].emplace_back(v, l);
        g[v].emplace_back(u, l);
    }

    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> q;

    if (k > 0)
    {
        forn(i, 1, k)
        {
            int x;
            cin >> x;
            dis[x] = 0;
            q.emplace(0, x);
        }
    }
    else
    {
        cout << -1 << endl;
        return;
    }

    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;

        for (auto [v, w] : g[u])
        {
            if (dis[v] > d + w)
            {
                dis[v] = d + w;
                q.emplace(dis[v], v);
            }
        }
    }

    i64 mn = INF;
    forn(i, 1, n)
    {
        if (dis[i] == 0)
        {
            continue;
        }
        if (dis[i] < mn)
        {
            mn = dis[i];
        }
    }

    cout << (mn == INF ? -1 : mn) << endl;
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