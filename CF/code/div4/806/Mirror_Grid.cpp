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

    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            g[i][j] = x - '0';
        }
    }

    int res = 0;

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        int sum = 0;
        for (int j = 0; j < n / 2; j++)
        {
            sum = g[i][j] + g[j][n - i - 1] + g[n - i - 1][n - j - 1] + g[n - j - 1][i];
            res += 4 - max(sum, 4 - sum);
        }
    }

    cout << res << endl;
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