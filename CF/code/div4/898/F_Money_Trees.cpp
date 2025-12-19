#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int mx = 0, res = 0;
    for (int l = 0, r = 0; r < n; r++)
    {
        if (r > 0 && h[r - 1] % h[r] != 0)
        {
            l = r;
            res = 0;
        }

        res += a[r];

        while (res > k)
        {
            res -= a[l++];
        }

        mx = max(mx, r - l + 1);
    }
    

    cout << mx << endl;
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