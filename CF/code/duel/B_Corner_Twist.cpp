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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            g[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            int x = s[j] - '0';
            g[i][j] = (x - g[i][j] + 3) % 3;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int x = g[i][j];
            if (x == 0)
            {
                continue;
            }
            g[i][j] = 0;
            g[i][m - 1] = (g[i][m - 1] + x) % 3;
            g[n - 1][j] = (g[n - 1][j] + x) % 3;
            g[n - 1][m - 1] = (g[n - 1][m - 1] - x + 3) % 3;
        }
    }

    bool flag = true;
    for (int j = 0; j < m; j++)
    {
        if (g[n - 1][j] != 0)
        {
            flag = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (g[i][m - 1] != 0)
        {
            flag = false;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
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