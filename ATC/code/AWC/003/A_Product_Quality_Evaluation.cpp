#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, k;
    cin >> n >> k;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        i64 a, b;
        cin >> a >> b;
        if ((__int128_t)a * b >= (__int128_t)k)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}