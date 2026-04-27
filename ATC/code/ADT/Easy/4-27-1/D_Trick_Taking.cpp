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
    int n, t;
    cin >> n >> t;

    priority_queue<pair<int, int>> pq1, pq2;
    vector<int> c(n), r(n);
    forn(i, 0, n - 1)
    {
        cin >> c[i];
    }
    forn(i, 0, n - 1)
    {
        cin >> r[i];
    }

    forn(i, 0, n - 1)
    {
        if (c[i] == t)
        {
            pq1.push({r[i], i + 1});
        }
        else if (c[i] == c[0])
        {
            pq2.push({r[i], i + 1});
        }
    }

    if (pq1.empty())
    {
        auto [x, idx] = pq2.top();
        cout << idx << endl;
    }
    else
    {
        auto [x, idx] = pq1.top();
        cout << idx << endl;
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