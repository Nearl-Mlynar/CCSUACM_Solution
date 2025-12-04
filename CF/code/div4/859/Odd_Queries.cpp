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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + (a[i - 1] & 1);
    }

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        if (k & 1)
        {
            cout << ((pref[n] - (pref[r] - pref[l - 1]) + (r - l + 1)) & 1 ? "YES" : "NO") << endl;
        }
        else
        {
            cout << ((pref[n] - (pref[r] - pref[l - 1])) & 1 ? "YES" : "NO") << endl;
        }
    }
    return;
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