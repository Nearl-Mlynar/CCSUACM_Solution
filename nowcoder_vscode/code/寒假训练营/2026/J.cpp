#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = 0;
    for (int x : a)
    {
        int idx = upper_bound(a.begin(), a.end(), x) - a.begin();

        if (idx + 1 >= ceil(0.8 * n))
        {
            res += x;
        }
    }
// 1 1 1 4 4 5
    cout << res << endl;
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