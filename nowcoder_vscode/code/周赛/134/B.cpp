#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    i64 ans = a;

    while (true)
    {
        i64 res1 = c / x;
        b += res1;
        c %= x;

        i64 res2 = b / y;
        if (res2 == 0)
        {
            break;
        }
        ans += res2;
        b %= y;
        c += res2;
    }

    cout << ans << endl;
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