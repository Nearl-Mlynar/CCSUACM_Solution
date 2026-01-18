#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int g[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int cnt[5] = {};
        for (int j = 0; j < 4; j++)
        {
            cnt[g[i][j]]++;
        }
        for (int k = 1; k <= 4; k++)
        {
            if (cnt[k] != 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int cnt[5] = {};
        for (int j = 0; j < 4; j++)
        {
            cnt[g[j][i]]++;
        }
        for (int k = 1; k <= 4; k++)
        {
            if (cnt[k] != 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    int cnt1[5] = {};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cnt1[g[i][j]]++;
        }
    }

    int cnt2[5] = {};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 2; j < 4; j++)
        {
            cnt2[g[i][j]]++;
        }
    }

    int cnt3[5] = {};
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cnt3[g[i][j]]++;
        }
    }

    int cnt4[5] = {};
    for (int i = 2; i < 4; i++)
    {
        for (int j = 2; j < 4; j++)
        {
            cnt4[g[i][j]]++;
        }
    }

    for (int k = 1; k <= 4; k++)
    {
        if (cnt1[k] != 1 || cnt2[k] != 1 || cnt3[k] != 1 || cnt4[k] != 1)
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