#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    y = min(y, 2 * x);
    i64 ans = 0;

    for (int k = 0; k < n; k++)
    {
        string s;
        cin >> s;
        int i = 0;
        while (i < m)
        {
            if (s[i] == '*')
            {
                i++;
                continue;
            }
            int j = i;
            while (j + 1 < m && s[j + 1] == '.')
            {
                j++;
            }
            int l = j - i + 1;
            ans += (l % 2) * 1LL * x + (l / 2) * 1LL * y;
            i = j + 1;
        }
    }
    cout << ans << endl;
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}