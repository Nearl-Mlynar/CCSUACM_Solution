#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    int res1 = 0, res2 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1)
        {
            res1 += x;
            cnt1++;
        }
        else
        {
            res2 += x;
            cnt2++;
        }
    }

    cout << (res1 * 2 >= 10 * cnt1 ? "LIVE" : "DEAD") << endl
         << (res2 * 2 >= 10 * cnt2 ? "LIVE" : "DEAD") << endl;
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