#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<i64> sorted = a;
    sort(sorted.begin(), sorted.end());

    vector<i64> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + sorted[i - 1];
    }

    vector<i64> ans(n);
    for (int i = 0; i < n; i++)
    {
        int cnt = upper_bound(sorted.begin(), sorted.end(), m - a[i]) - sorted.begin();

        cnt -= (a[i] <= m - a[i] ? 1 : 0);

        i64 res = pref[cnt + (a[i] <= m - a[i] ? 1 : 0)];
        if (a[i] <= m - a[i])
        {
            res -= a[i];
        }

        ans[i] = a[i] * (cnt + 1) - pref[n] + res;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}