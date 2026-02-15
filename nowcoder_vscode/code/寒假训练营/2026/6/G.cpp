#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> x(n), y(m);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> y[i];
    }

    i64 left = 0, right = l;

    if (right > x[0])
    {
        cout << "YES" << endl;
        return;
    }

    vector<i64> pref(n + 1);

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + x[i - 1];
    }

    for (int a : y)
    {
        left += a, right += a;

        if (lower_bound(pref.begin(), pref.end(), right) != upper_bound(pref.begin(), pref.end(), left))
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;

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