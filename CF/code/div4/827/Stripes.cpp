#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    vector<vector<char>> g(8, vector<char>(8));

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 8; j++)
        {
            if (g[i][j] == 'R')
            {
                cnt++;
            }
        }

        if (cnt == 8)
        {
            cout << 'R' << endl;
            return;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 8; j++)
        {
             if (g[j][i] == 'B')
            {
                cnt++;
            }
        }

        if (cnt == 8)
        {
            cout << 'B' << endl;
            return;
        }
    }

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