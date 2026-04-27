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
    vector<int> a(n + 1);
    forn(i, 1, n)
    {
        cin >> a[i];
    }

    int L = n, r;
    while (L > 0 && a[L] == L)
    {
        L--;
    }

    double res = 1.0, p;
    forn(i, 0, m - 1)
    {
        cin >> r >> p;
        if (r >= L)
        {
            res *= (1.0 - p);
        }
    }

    cout << fixed << setprecision(6) << 1.0 - (L == 0 ? 0 : res) << endl;
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