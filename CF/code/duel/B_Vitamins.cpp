#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; i >= b; --i)
#define all(v, l, r, ...) v.begin() + l, v.begin() + r, ##__VA_ARGS__
#define rall(v, l, r, ...) v.rbegin() + l, v.rbegin() + r, ##__VA_ARGS__
#define endl '\n'

const i64 mod = 1e9 + 7;
const i64 N = 1e4 + 7;
i64 dp[1 << 3];

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    for (int i = 0; i < 8; ++i)
    {
        dp[i] = LLONG_MAX;
    }
    dp[0] = 0;
    return 0;
}();

void solve()
{
    int n;
    cin >> n;

    forn(i, 0, n - 1)
    {
        int x;
        string y;
        cin >> x >> y;
        int mask = 0;
        for (char c : y)
        {
            int x = c - 'a';
            mask |= 1 << x;
        }

        rforn(j, 7, 0)
        {
            if (dp[j] != LLONG_MAX)
            {
                dp[j | mask] = min(dp[j | mask], dp[j] + x);
            }
        }
    }

    cout << (dp[7] == LLONG_MAX ? -1 : dp[7]) << endl;

    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}