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
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = x2 - x1, dy = y2 - y1;

    int n;
    int cnt[4] = {0};
    cin >> n;
    forn(i, 1, n)
    {
        char c;
        cin >> c;

        if (c == 'N')
        {
            cnt[0]++;
        }
        else if (c == 'S')
        {
            cnt[1]++;
        }
        else if (c == 'W')
        {
            cnt[2]++;
        }
        else if (c == 'E')
        {
            cnt[3]++;
        }
    }

    bool flag = true;

    if (dx > 0)
    {
        if (cnt[3] < dx)
        {
            flag = false;
        }
    }
    else if (dx < 0)
    {
        if (cnt[2] < -dx)
        {
            flag = false;
        }
    }

    if (dy > 0)
    {
        if (cnt[0] < dy)
        {
            flag = false;
        }
    }
    else if (dy < 0)
    {
        if (cnt[1] < -dy)
        {
            flag = false;
        }
    }

    if (flag)
    {
        cout << abs(dx) + abs(dy) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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