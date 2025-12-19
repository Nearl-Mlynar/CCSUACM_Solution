#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    string s;

    int n, k;
    cin >> n >> k >> s;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            continue;
        }
        else
        {
            i += k - 1;
            res++;
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