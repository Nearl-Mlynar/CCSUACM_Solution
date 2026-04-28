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
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> s(n);
    i64 res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        res += s[i];
    }

    int cnt = 0;
    priority_queue<int> pq(s.begin() + 1, s.end());
    while (x * s[0] / res < y)
    {
        int t = pq.top();
        pq.pop();
        res -= t;
        cnt++;
    }

    cout << cnt << endl;

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