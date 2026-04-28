#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; >= b; --i)
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

void f1(vector<string> &g)
{
    int n = g.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(g[i][j], g[j][i]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        reverse(g[i].begin(), g[i].end());
    }
}

int f2(const vector<string> &a, const vector<string> &b)
{
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;

    vector<string> s(n), t(n);
    forn(i, 0, n - 1) cin >> s[i];
    forn(i, 0, n - 1) cin >> t[i];

    int mn = INT_MAX;
    mn = min(mn, f2(s, t));
    f1(s);
    mn = min(mn, f2(s, t) + 1);
    f1(s);
    mn = min(mn, f2(s, t) + 2);
    f1(s);
    mn = min(mn, f2(s, t) + 3);

    cout << mn << endl;
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