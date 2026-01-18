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
    string ans = "";
    bool flag = true;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (!flag)
        {
            ans += '0';
            continue;
        }
        if (s[i] - '0' >= 5)
        {
            if (i == 0)
            {
                ans += '1';
            }
            else
            {
                ans[i - 1] = ans[i - 1] + 1;
            }

            flag = false;
            ans += '0';
        }
        else
        {
            ans += s[i];
        }
    }

    if(flag)
    {
        int n = ans.size();
        ans[n - 1] = '0';
    }

    cout << ans << endl;
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