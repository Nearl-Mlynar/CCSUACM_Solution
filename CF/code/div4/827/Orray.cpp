#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<bool> vis(n);
    int res_or = 0;
    for (int i = 0; i < min(31LL, n); i++)
    {
        int mx = 0, idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (vis[j])
            {
                continue;
            }
            else if ((res_or | a[j]) > mx)
            {
                idx = j;
                mx = (res_or | a[j]);
            }
        }

        cout << a[idx] << " ";
        vis[idx] = true;
        res_or |= a[idx];
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cout << a[i] << " ";
        }
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