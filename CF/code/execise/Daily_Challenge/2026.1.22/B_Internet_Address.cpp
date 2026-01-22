#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    string ans, s;
    int idx;

    cin >> s;

    if (s[0] == 'h')
    {
        ans += "http://";
        idx = 4;
    }
    else
    {
        ans += "ftp://";
        idx = 3;
    }

    for (int i = s.size() - 3; i >= idx; i--)
    {
        if (s[i] == 'r' && s[i + 1] == 'u')
        {
            cout << ans + s.substr(idx, i - idx) + ".ru/" + s.substr(i + 2) << endl;
            return ;
        }
    }

    cout << ans + s.substr(idx, (int)s.size() - 2 - idx) + ".ru" << endl;
    
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