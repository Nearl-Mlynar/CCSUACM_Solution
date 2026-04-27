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

i64 ksm(i64 a, i64 b, i64 p)
{
    i64 res = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
        {
            res = (res + a) % p;
        }
        b >>= 1;
        a = (a * a) % p;
    }

    return res % p;
}

int init = []()
{
    return 0;
}();

i64 memo[25][25][25];

i64 w(i64 a, i64 b, i64 c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }

    if (memo[a][b][c] != 0)
    {
        return memo[a][b][c];
    }

    if (a < b && b < c)
    {
        memo[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        memo[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return memo[a][b][c];
}

void solve()
{
    i64 a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
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