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
    int h, n;
    cin >> h >> n;

    vector<int> a(n), c(n);
    i64 sum = 0;
    forn(i, 0, n - 1)
    {
        cin >> a[i];
        sum += a[i];
    }

    forn(i, 0, n - 1)
    {
        cin >> c[i];
    }

    auto check = [&](long long m) -> bool
    {
        i64 res = sum;
        forn(i, 0, n - 1)
        {
            res += 1LL * (m - 1) / c[i] * a[i];
            if (res >= h)
            {
                return true;
            }
        }
        return false;
    };

    long long l = 0, r = 1e12;
    while (l + 1 < r)
    {
        long long mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    cout << r << endl;

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
int init = []()
{
    return 0;
}();

void solve()
{
    
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