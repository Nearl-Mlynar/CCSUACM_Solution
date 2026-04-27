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

void solve()
{
    int n;
    i64 m;
    cin >> n >> m;

    vector<i64> a(n), pref(n + 1, 0);
    forn(i, 0, n - 1)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] ^ a[i]; 
    }

    i64 mx = 0;
    rforn(j, 30, 0)
    {
        i64 mask = mx | (1LL << j);

        if ((pref[n] & mask) != (m % 2 == 1 ? mask : 0))
        {
            continue;
        }

        int cnt = 0;
        i64 prev = mask;
        forn(i, 1, n)
        {
            if ((pref[i] & mask) == prev)
            {
                cnt++;
                prev ^= mask; 
            }
        }

        if (cnt >= m)
        {
            mx = mask;
        }
    }

    cout << mx << endl;
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