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
const i64 N = 3e5 + 7;
bool cnt[105][105];

int ios = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    return 0;
}();

void solve()
{
    int n, m, r, res = 0;
    cin >> n >> m >> r;

    forn(k, 1, m)
    {
        int x, y;
        cin >> x >> y;

        forn(i, max(1, x - r), min(n, x + r))
        {
            forn(j, max(1, y - r), min(n, y + r))
            {
                int dx = i - x, dy = j - y;
                if (dx * dx + dy * dy <= r * r && !cnt[i][j])
                {
                    res++;
                    cnt[i][j] = true;
                }
            }
        }
    }

    cout << res << endl;
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