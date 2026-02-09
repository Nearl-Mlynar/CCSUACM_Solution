#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        a[i] = max({a[i], b[i], a[i + 1]});
    }

    vector<i64> pref(n + 1);

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << pref[r] - pref[l - 1] << " ";
    }

    cout << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}