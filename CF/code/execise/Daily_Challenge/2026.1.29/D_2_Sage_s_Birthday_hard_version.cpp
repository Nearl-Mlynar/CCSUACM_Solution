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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n <= 2)
    {
        cout << 0 << endl;
        for (int x : a)
        {
            cout << x << ' ';
        }
        cout << endl;
        return;
    }

    sort(a.begin(), a.end());
    vector<int> ans(n);

    int idx = 0;
    for (int i = 1; i < n; i += 2)
    {
        ans[i] = a[idx++];
    }
    for (int i = 0; i < n; i += 2)
    {
        ans[i] = a[idx++];
    }

    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
        {
            cnt++;
        }
    }

    cout << cnt << endl;
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
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}