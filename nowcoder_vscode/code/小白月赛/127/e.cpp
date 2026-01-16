#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl '\n'
const i64 mod = 998244353;
const int MAXN = 2e5 + 5;
vector<int> g[MAXN];
int d[MAXN], siz[MAXN];
i64 sum[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    i64 ans = 0;

    auto dfs = [&](auto &&dfs, int u, int fa) -> void
    {
        siz[u] = 1;
        sum[u] = d[u];

        for (int v : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            d[v] = d[u] + 1;
            dfs(dfs, v, u);

            ans = (ans + 1LL * siz[v] * (n - siz[v])) % mod;

            i64 sub = (sum[v] - 1LL * siz[v] * d[u] - siz[v]) % mod;

            ans = (ans - sub + mod) % mod;

            siz[u] += siz[v];
            sum[u] += sum[v];
        }
    };

    d[1] = 0;
    dfs(dfs, 1, 0);

    cout << ans << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
