#include <bits/stdc++.h>
using ll = long long;
const int N = 1e5 + 5;
int a[N];
void fc(int n)
{
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int k;
        std::cin >> k;
        g[k].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::vector<ll> ans(n + 1), cnt(n + 1), mx(n + 1);
    int cn = 0;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        int m = mx[a[u]];
        ans[u] = ans[f] - 1LL * mx[a[u]];
        mx[a[u]] = cn;
        ans[u] += cn;

        if (cnt[a[u]] == 0)
            cn++;
        cnt[a[u]]++;

        for (int v : g[u])
        {
            self(self, v, u);
        }
        mx[a[u]] = m;
        cnt[a[u]]--;
        if (!cnt[a[u]])
            cn--;
    };
    dfs(dfs, 1, 0);
    for (int i = 2; i <= n; i++)
        std::cout << ans[i] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    while (std::cin >> n)
    {
        fc(n);
    }
}