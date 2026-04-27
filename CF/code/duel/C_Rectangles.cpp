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

struct Ce
{
    int x1, y1, x2, y2;
};

Ce pre[N], suf[N], a[N];

void solve()
{
    int n;
    cin >> n;
    forn(i, 1, n)
    {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }

    pre[0] = {-2000000000, -2000000000, 2000000000, 2000000000};
    forn(i, 1, n)
    {
        pre[i].x1 = max(pre[i - 1].x1, a[i].x1);
        pre[i].y1 = max(pre[i - 1].y1, a[i].y1);
        pre[i].x2 = min(pre[i - 1].x2, a[i].x2);
        pre[i].y2 = min(pre[i - 1].y2, a[i].y2);
    }

    suf[n + 1] = {-2000000000, -2000000000, 2000000000, 2000000000};
    rforn(i, n, 1)
    {
        suf[i].x1 = max(suf[i + 1].x1, a[i].x1);
        suf[i].y1 = max(suf[i + 1].y1, a[i].y1);
        suf[i].x2 = min(suf[i + 1].x2, a[i].x2);
        suf[i].y2 = min(suf[i + 1].y2, a[i].y2);
    }

    forn(i, 1, n)
    {
        Ce ans;
        ans.x1 = max(pre[i - 1].x1, suf[i + 1].x1);
        ans.y1 = max(pre[i - 1].y1, suf[i + 1].y1);
        ans.x2 = min(pre[i - 1].x2, suf[i + 1].x2);
        ans.y2 = min(pre[i - 1].y2, suf[i + 1].y2);

        if (ans.x1 <= ans.x2 && ans.y1 <= ans.y2)
        {
            cout << ans.x1 << " " << ans.y1 << endl;
            return;
        }
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