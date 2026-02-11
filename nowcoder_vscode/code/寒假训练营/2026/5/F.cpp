#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, a, b;
    cin >> n >> a >> b;

    i64 ans = 0;
    i64 c = a + b;
    {
        i64 q = n / 8;
        for (int i = 0; i < 200; i++)
        {
            if (q - i < 0)
            {
                break;
            }
            ans = max(ans, c * (q - i) + ((n - 8 * (q - i)) / 2) * b);
            ans = max(ans, c * (q - i) + ((n - 8 * (q - i)) / 7) * a);
        }
    }
    {
        i64 q = n / 8;
        for (int i = 0; i < 200; i++)
        {
            if (i > q)
            {
                break;
            }
            ans = max(ans, c * i + ((n - 8 * i) / 2) * b);
            ans = max(ans, c * i + ((n - 8 * i) / 7) * a);
        }
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}