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
    vector<int> b(n);
    vector<int> pref(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    b[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = max(b[i - 1], a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    vector<int> ans(q);

    int x;
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        ans[i] = pref[upper_bound(b.begin(), b.end(), x) - b.begin()];
    }

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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