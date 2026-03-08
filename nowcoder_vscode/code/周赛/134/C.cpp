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
    vector<i64> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    vector<i64> a(n);
    a[0] = d[0];
    for (int i = 1; i < n; i++)
    {
        a[i] = min(a[i - 1], d[i]);
    }

    i64 res = 0; 
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= res)
        {
            res++; 
        }
    }

    cout << res << endl;
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