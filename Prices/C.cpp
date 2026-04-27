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
    while (cin >> n >> m)
    {
        vector<string> str(n);
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }

        auto f = [&](int i, int j) -> vector<pair<int, int>>
        {
            vector<pair<int, int>> g;
            char ch = str[i][j];
            if (ch == '^')
            {
                if (i + 1 < n && j - 1 >= 0 && str[i + 1][j - 1] == 'v')
                {
                    g.push_back({i + 1, j - 1});
                }
                if (i + 1 < n && j + 1 < m && str[i + 1][j + 1] == 'v')
                {
                    g.push_back({i + 1, j + 1});
                }
            }
            else if (ch == 'v')
            {
                if (i - 1 >= 0 && j - 1 >= 0 && str[i - 1][j - 1] == '^')
                {
                    g.push_back({i - 1, j - 1});
                }
                if (i - 1 >= 0 && j + 1 < m && str[i - 1][j + 1] == '^')
                {
                    g.push_back({i - 1, j + 1});
                }
            }
            else if (ch == '<')
            {
                if (i - 1 >= 0 && j + 1 < m && str[i - 1][j + 1] == '>')
                {
                    g.push_back({i - 1, j + 1});
                }
                if (i + 1 < n && j + 1 < m && str[i + 1][j + 1] == '>')
                {
                    g.push_back({i + 1, j + 1});
                }
            }
            else if (ch == '>')
            {
                if (i - 1 >= 0 && j - 1 >= 0 && str[i - 1][j - 1] == '<')
                {
                    g.push_back({i - 1, j - 1});
                }
                if (i + 1 < n && j - 1 >= 0 && str[i + 1][j - 1] == '<')
                {
                    g.push_back({i + 1, j - 1});
                }
            }
            return g;
        };

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && (str[i][j] == '^' || str[i][j] == 'v' || str[i][j] == '<' || str[i][j] == '>'))
                {
                    int cnt = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;

                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        cnt++;

                        for (auto &[nx, ny] : f(x, y))
                        {
                            if (!vis[nx][ny])
                            {
                                vis[nx][ny] = true;
                                q.push({x, y});
                            }
                        }
                    }
                    res += cnt / 3;
                }
            }
        }
        cout << res << endl;
    }
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