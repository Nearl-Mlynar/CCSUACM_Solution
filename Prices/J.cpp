#include <bits/stdc++.h>
using ll = long long;
const ll mod = 1e9 + 7;
void fc(int n, int m, int l, int r)
{
    std::vector<ll> a(n + 1), b(m + 1);
    for (int i = 0; i <= n; i++)
        std::cin >> a[i];
    for (int i = 0; i <= m; i++)
        std::cin >> b[i];

    for (int i = 1; i <= m; i++)
        b[i] = (b[i] + b[i - 1]) % mod;
    ll ans = 0;

    for (int i = std::max(0, l - m); i <= std::min(r, n); i++)
    {
        ll R = b[std::min(r - i, m)];
        ll L = (l - i - 1 >= 0 ? b[l - i - 1] : 0);

        // std::cout<<R<<" "<<L<<"\n";
        ans = (ans + a[i] * (R - L) % mod) % mod;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, l, r;
    while (std::cin >> n >> m >> l >> r)
    {
        fc(n, m, l, r);
    }
}