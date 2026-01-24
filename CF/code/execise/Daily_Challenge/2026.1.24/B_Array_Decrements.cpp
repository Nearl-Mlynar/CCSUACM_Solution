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
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int d = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != 0)
        {
            d = min(d, a[i] - b[i]);
        }
    }

    if (d < 0)
    {
        cout << "NO" << endl;
        return;
    }

    if (d == INT_MAX)
    {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if ((a[i] - b[i] > d) || (b[i] != 0 && a[i] - b[i] < d))
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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