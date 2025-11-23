#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int mm = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int res = 0;
            for (int k = 0; k < m; k++)
            {
                res += abs(s[i][k] - s[j][k]);
            }
            mm = min(mm, res);
        }
    }

    cout << mm << endl;
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