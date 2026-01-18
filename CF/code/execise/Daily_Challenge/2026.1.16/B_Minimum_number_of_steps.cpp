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
    cin >> s;

    long long res = 0, cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
        {
            cnt++;
        }
        else
        {
            res = (res + cnt) % mod;
            cnt = cnt * 2 % mod;
        }
    }
    cout << res % mod << endl;
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