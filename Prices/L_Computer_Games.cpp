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
    int n, k, x;
    i64 m;
    cin >> n >> k >> x >> m;

    vector<int> s(n), r(n);
    forn(i, 0, n - 1)
    {
        cin >> s[i];
    }
    forn(i, 0, n - 1)
    {
        cin >> r[i];
    }

    vector<pair<int, int>> a(n);
    int mx = 0;
    forn(i, 0, n - 1)
    {
        a[i] = {s[i], r[i]};
        mx = max(mx, r[i]);
    }

    sort(a.begin(), a.end());

    auto check = [&](int mid) -> bool
    {
        i64 res = 0;
        int hcnt = 0, ecnt = 0;

        for (auto &[ns, nr] : a)
        {
            if (hcnt < x && nr >= mid)
            {
                res += ns;
                hcnt++;
            }
            else if (ecnt < k - x)
            {
                res += ns;
                ecnt++;
            }

            if (hcnt == x && ecnt == k - x)
            {
                break;
            }
        }

        if (hcnt < x || ecnt < k - x)
        {
            return false;
        }

        return res <= m;
    };

    int left = 0, right = mx + 1;
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        (check(mid) ? left : right) = mid;
    }

    cout << (left == 0 ? -1 : left) << endl;
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