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
    i64 x, y, z, k, mx = 0;
    cin >> x >> y >> z >> k;

    forn(i, 1, x)
    {
        if (i > k)
        {
            break;
        }

        forn(j, 1, y)
        {
            if (i * j > k)
            {
                break;
            }

            if (k % (i * j) == 0)
            {
                if (k / (i * j) <= z)
                {
                    mx = max(mx, (x - i + 1) * (y - j + 1) * (z - k / (i * j) + 1));
                }
            }
        }
    }

    cout << mx << endl;
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