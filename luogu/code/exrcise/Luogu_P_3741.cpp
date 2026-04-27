#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; i >= b; --i)
#define all(v, l, r, ...) v.begin() + l, v.begin() + r, ##__VA_ARGS__
#define rall(v, l, r, ...) v.rbegin() + l, v.rbegin() + r, ##__VA_ARGS__
#define endl '\n'

const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int ios = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    return 0;
}();

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int res = 0;
    vector<bool> vis(n, false);

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            res++;
            vis[i] = vis[i + 1] = true;
        }
    }

    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (!vis[i] && !vis[i + 1])
        {
            if (s[i] == 'V' && s[i + 1] == 'V')
            {
                flag = true;
                break;
            }
            if (s[i] == 'K' && s[i + 1] == 'K')
            {
                flag = true;
                break;
            }
        }
    }

    cout << res + flag << endl;
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}