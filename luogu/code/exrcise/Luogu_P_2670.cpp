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

int cnt[105][105];

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
    int n, m;
    cin >> n >> m;

    char s[n][m];
    int dirt[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    forn(i, 0, n - 1)
    {
        forn(j, 0, m - 1)
        {
            cin >> s[i][j];
        }
    }

    forn(i, 0, n - 1)
    {
        forn(j, 0, m - 1)
        {
            if (s[i][j] == '*')
            {
                cnt[i][j] = INT_MAX;
                forn(k, 0, 7)
                {
                    int nx = i + dirt[k][0], ny = j + dirt[k][1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    {
                        continue;
                    }
                    if (s[nx][ny] != '*')
                    {
                        cnt[nx][ny]++;
                    }
                }
            }
        }
    }

    forn(i, 0, n - 1)
    {
        forn(j, 0, m - 1)
        {
            if (cnt[i][j] == INT_MAX)
            {
                cout << '*';
            }
            else
            {
                cout << cnt[i][j];
            }
        }
        cout << endl;
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