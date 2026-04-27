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
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    sort(a.rbegin(), a.rend());

    i64 res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (a[i] % 2 == 0)
            {
                res1 += a[i];
            }
        }
        else
        {
            if (a[i] % 2 == 1)
            {
                res2 += a[i];
            }
        }
    }

    if (res1 == res2)
    {
        cout << "Tie" << endl;
    }
    else
    {
        cout << (res1 > res2 ? "Alice" : "Bob") << endl;
    }
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