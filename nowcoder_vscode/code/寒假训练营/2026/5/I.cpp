#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
i64 d1[N], d2[N];

void solve()
{
    i64 n, m, h;
    cin >> n >> m >> h;

    vector<i64> p(m + 1), f(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i] >> f[i];
    }

    auto check = [&](int k)
    {
        memset(d1, 0, sizeof(i64) * (n + 5));
        memset(d2, 0, sizeof(i64) * (n + 5));

        auto add = [&](int l, int r, i64 a, i64 b)
        {
            d2[l] += a;
            d2[r + 1] -= a;
            d1[l] += b;
            d1[r + 1] -= b;
        };

        for (int i = 1; i <= k; i++)
        {
            add(max(1LL, p[i] - f[i] + 1), p[i], 1, f[i] - p[i]);
            add(p[i] + 1, min(n, p[i] + f[i] - 1), -1, f[i] + p[i]);
        }

        i64 cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt1 += d1[i];
            cnt2 += d2[i];
            if (cnt2 * i + cnt1 > h)
            {
                return true;
            }
        }
        return false;
    };

    if (!check(m))
    {
        cout << "No" << endl;
        return;
    }

    int l = 0, r = m + 1;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    cout << "Yes" << endl;
    cout << r << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
