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

    int n = s.size();
    int res = 0;
    bool flag = (s[0] == 'B' || s[n - 1] == 'B');

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1] && s[i] == 'B')
        {
            flag = true;
            break;
        }
    }

    vector<int> a;
    int cnt = 0;
    for (char x : s)
    {
        if (x == 'A')
        {
            cnt++;
        }
        else
        {
            if (cnt != 0)
            {
                a.push_back(cnt);
            }
            cnt = 0;
        }
    }

    if (cnt != 0)
    {
        a.push_back(cnt);
    }

    sort(a.begin(), a.end());

    if (a.empty())
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < a.size(); i++)
    {
        res += a[i];
    }

    cout << res + (flag ? a[0] : 0) << endl;
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
