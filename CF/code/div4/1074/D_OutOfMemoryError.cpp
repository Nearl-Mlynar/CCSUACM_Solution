#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> op(m);
    for (int i = 0; i < m; i++)
    {
        cin >> op[i].first >> op[i].second;
        op[i].first--;
    }

    vector<int> add(n, 0);
    vector<int> vis(n, 0);

    int t = 0, lst = -1;

    for (int i = 0; i < m; i++)
    {
        auto &[idx, c] = op[i];

        if (vis[idx] != t)
        {
            vis[idx] = t;
            add[idx] = 0;
        }

        if (a[idx] + add[idx] + c > h)
        {
            lst = i;
            t++;
        }
        else
        {
            add[idx] += c;
        }
    }

    t++;
    for (int i = lst + 1; i < m; i++)
    {
        auto &[idx, c] = op[i];

        if (vis[idx] != t)
        {
            vis[idx] = t;
            add[idx] = 0;
        }

        add[idx] += c;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == t)
        {
            cout << a[i] + add[i] << " ";
        }
        else
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
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}