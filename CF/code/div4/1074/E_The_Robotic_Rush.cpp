#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    string s;
    cin >> s;

    sort(b.begin(), b.end());

    vector<int> L, R;

    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

        if (idx > 0)
        {
            L.push_back(a[i] - b[idx - 1]);
        }
        if (idx < m)
        {
            R.push_back(b[idx] - a[i]);
        }
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int res = 0;
    int mn = 0, mx = 0;

    for (int i = 0; i < k; i++)
    {
        res += s[i] == 'L' ? -1 : 1;

        mn = min(mn, res);
        mx = max(mx, res);

        int dl = upper_bound(L.begin(), L.end(), -mn) - L.begin();
        int dr = upper_bound(R.begin(), R.end(), mx) - R.begin();

        cout << n - (dl + dr) << " ";
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