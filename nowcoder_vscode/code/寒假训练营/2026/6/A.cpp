#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, w;
    cin >> n >> w;

    vector<i64> x(n), y(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        sum += y[i];
    }

    if (w >= sum)
    {
        d64 ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += 1.0 * x[i];
        }
        cout << fixed << setprecision(9) << ans << endl;
        return;
    }

    d64 left = 0, right = 1;
    vector<d64> z(n);

    auto check = [&](d64 m) -> pair<d64, d64>
    {
        d64 res1 = 0;
        d64 res2 = 0;
        d64 k = (m >= 1.0 - 1e-15) ? 0 : sqrt(max(0.0L, 1.0 - m * m));
        for (int i = 0; i < n; i++)
        {
            d64 a = x[i], b = y[i], c = 0;
            if (m < 1.0 - 1e-12 || k >= 1e-12)
            {
                c = m * a / k;
                if (c > b)
                {
                    c = b;
                }
                if (c < 0)
                {
                    c = 0;
                }
            }
            z[i] = c;
            res1 += b - c;
            res2 += sqrtl(a * a + c * c);
        }

        return {res1, res2};
    };

    for (int i = 0; i < 100; i++)
    {
        d64 mid = (left + right) * 0.5;
        if (check(mid).first > (d64)w + 1e-12)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    cout << fixed << setprecision(9) << check(left).second << endl;
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