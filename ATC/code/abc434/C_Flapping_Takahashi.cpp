#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;

void solve()
{
    int n, H;
    cin >> n >> H;

    vector<int> t(n), l(n), u(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> l[i] >> u[i];
    }

    int low = l[n - 1], high = u[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        low = max(l[i], low - (t[i + 1] - t[i]));
        high = min(u[i], high + t[i + 1] - t[i]);

        if (low > high)
        {
            cout << "No" << endl;
            return;
        }
    }

    if (H >= low - t[0] && H <= high + t[0])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return;
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
