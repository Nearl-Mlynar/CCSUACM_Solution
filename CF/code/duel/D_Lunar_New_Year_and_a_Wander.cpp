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
vector<int> g[N];
bool vis[N];
int n, m;

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
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> res;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        res.push_back(u);

        for (int v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    for (int x : res)
    {
        cout << x << ' ';
    }
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