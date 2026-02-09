#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end()); 

    vector<i64> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + b[i - 1];
    }

    set<int> st(a.begin(), a.end());

    i64 ans = 0;
    for (int x : st)
    {
        int cnt = a.end() - lower_bound(a.begin(), a.end(), x);
        int k = upper_bound(pref.begin(), pref.end(), cnt) - pref.begin() - 1;
        ans = max(ans, 1LL * x * k);
    }

    cout << ans << endl;

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