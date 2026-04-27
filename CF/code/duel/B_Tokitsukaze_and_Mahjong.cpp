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
    vector<string> str(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> str[i];
    }

    sort(all(str, 0, 3));

    int x = str[0][0] - '0', y = str[1][0] - '0', z = str[2][0] - '0';
    char c1 = str[0][1], c2 = str[1][1], c3 = str[2][1];

    bool flag0 = false;
    if (x == y && y == z && c1 == c2 && c2 == c3)
    {
        flag0 = 1;
    }
    if (c1 == c2 && c2 == c3 && x + 1 == y && y + 1 == z)
    {
        flag0 = 1;
    }

    if (flag0)
    {
        cout << 0 << endl;
        return;
    }

    bool flag1 = false;
    if ((x == y && c1 == c2) || (y == z && c2 == c3) || (x == z && c1 == c3))
    {
        flag1 = 1;
    }
    if (c1 == c2 && (y - x == 1 || y - x == 2))
    {
        flag1 = 1;
    }
    if (c2 == c3 && (z - y == 1 || z - y == 2))
    {
        flag1 = 1;
    }
    if (c1 == c3 && (z - x == 1 || z - x == 2))
    {
        flag1 = 1;
    }

    if (flag1)
    {
        cout << 1 << endl;
        return;
    }

    cout << 2 << endl;
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