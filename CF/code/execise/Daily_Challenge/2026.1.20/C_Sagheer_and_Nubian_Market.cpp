#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

i64 a[N], b[N];

void solve()
{
    i64 n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](int m) -> pair<bool, i64>
    {
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i] + 1LL * (i + 1) * m;
        }

        sort(b, b + n);

        i64 res = 0;
        for (int i = 0; i < m; i++)
        {
            res += b[i];
            if (res > s)
            {
                return {false, 0};
            }
        }

        return {true, res};
    };

    int l = 0, r = n + 1;
    i64 ans = 0;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        auto [flag, res] = check(mid);
        if (flag)
        {
            ans = res;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << " " << ans << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    i64 T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}