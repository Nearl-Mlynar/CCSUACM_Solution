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

int fast_io = []()
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<unsigned long long>> a(n + 1, vector<unsigned long long>(m + 1)), pref(n + 1, vector<unsigned long long>(m + 1));

    forn(i, 1, n)
    {
        forn(j, 1, m)
        {
            cin >> a[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }

    unsigned long long res = 0;
    forn(i, 1, q)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        res ^= pref[x][y] - pref[u - 1][y] - pref[x][v - 1] + pref[u - 1][v - 1];
    }

    cout << res << endl;
    return;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}