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
    int n, v;
    cin >> n >> v;

    vector<int> a(n), b(n);

    forn(i, 0, n - 1)
    {
        cin >> a[i];
    }

    forn(i, 0, n - 1)
    {
        cin >> b[i];
    }

    double mx = LLONG_MAX;
    int res = 0;
    forn(i, 0, n - 1)
    {
        res += a[i];
        mx = min(mx, 1.0 * b[i] / a[i]);
    }

    cout << fixed << setprecision(10) << min(res * mx, 1.0 * v) << endl;
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