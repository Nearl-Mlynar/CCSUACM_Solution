#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int g[3][3];
    int cnt[10] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> g[i][j];
            cnt[g[i][j]]++;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        if (cnt[i] != 1)
        {
            cout << "No" << endl;
            return;
        }
    }

    int res = g[0][0] + g[0][1] + g[0][2];
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += g[i][j];
        }

        if (sum != res)
        {
            cout << "No" << endl;
            return;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += g[i][j];
        }

        if (sum != res)
        {
            cout << "No" << endl;
            return;
        }
    }

    int sum1 = g[0][0] + g[1][1] + g[2][2];
    int sum2 = g[2][0] + g[1][1] + g[0][2];

    if (sum1 != res || sum2 != res)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

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