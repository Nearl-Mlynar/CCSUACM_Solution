#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl '\n'
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, x;
    cin >> n >> x;

    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<i64> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    i64 l = -1, r = a.back() + x + 1;

    while (l + 1 < r)
    {
        i64 mid = l + (r - l) / 2;
        int idx = lower_bound(a.begin(), a.end(), mid) - a.begin();

        if (mid * idx - pref[idx] > x)
        {
            r = mid; 
        }
        else
        {
            l = mid; 
        }
    }

    cout << l << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}