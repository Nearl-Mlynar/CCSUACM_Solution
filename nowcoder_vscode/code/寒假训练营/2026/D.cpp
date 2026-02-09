#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    i64 x1, y1;
    i64 d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve()
{
    i64 x, a, s;
    cin >> x >> a >> s;

    i64 c1, c2;
    i64 g = exgcd(a, s, c1, c2);

    if (x % g != 0)
    {
        cout << "No" << endl;
        return;
    }

    i64 cnt1 = s / g;
    i64 cnt2 = a / g;

    c1 *= x / g;
    c2 *= x / g;

    c1 -= c1 / cnt1 * cnt1;
    c2 += c1 / cnt1 * cnt2;

    if (c1 < 0)
    {
        c1 += cnt1;
        c2 -= cnt2;
    }

    i64 k1 = -1, k2 = -1, mm = INT_MAX;

    for (i64 i = 0;; ++i)
    {
        i64 sum1 = c1 + i * cnt1;
        i64 sum2 = c2 - i * cnt2;

        if (sum1 < 0 || sum2 < 0)
        {
            break;
        }

        i64 mx = max(sum1, sum2);
        if (k1 == -1 || mx < mm)
        {
            mm = mx;
            k1 = sum1;
            k2 = sum2;
        }
    }

    if (k1 == -1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        cout << k1 << " " << k2 << endl;
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
