#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    while (q--)
    {
        int x;
        cin >> x;
        auto it = lower_bound(pref.begin() + 1, pref.end(), x);
        if (it == pref.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << it - pref.begin() << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}