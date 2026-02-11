#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, q, s;
    cin >> n >> q >> s;

    vector<i64> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    vector<i64> pref(n + 1);
    pref[0] = s;

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + t[i - 1];
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        cout << pref[x - 1] + y - 1 << endl;
    }
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