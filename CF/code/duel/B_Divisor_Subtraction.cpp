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

i64 f(i64 n)
{
    if (n % 2 == 0)
    {
        return 2;
    }
    for (i64 i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return n;
}

void solve()
{
    i64 n, ans;
    cin >> n;

    if (n % 2 == 0)
    {
        ans = n / 2;
    }
    else
    {
        i64 d = f(n);
        ans = 1 + (n - d) / 2;
    }

    cout << ans << endl;
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