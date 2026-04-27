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

int fast_io = []()
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

    auto f = [](string x, string y) -> string
    {
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int yu = 0;
        int sz1 = x.size(), sz2 = y.size();
        int a, b;
        string ans = "";
        for (int i = 0; i < max(sz1, sz2); i++)
        {
            if (i < sz1)
            {
                a = x[i] - '0';
            }
            else
            {
                a = 0;
            }

            if (i < sz2)
            {
                b = y[i] - '0';
            }
            else
            {
                b = 0;
            }

            ans += (a + b + yu) % 10 + '0';
            yu = (a + b + yu) / 10;
        }
        if (yu)
        {
            ans += yu + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    };

    string res(100005, '9');
    int mid = n / 2;
    for (int i = mid; i >= 1; --i)
    {
        if (s[i] != '0')
        {
            string c = f(s.substr(0, i), s.substr(i));
            if (c.size() < res.size() || (c.size() == res.size() && c < res))
            {
                res = c;
            }
            break;
        }
    }
    for (int i = mid + 1; i <= n - 1; ++i)
    {
        if (s[i] != '0')
        {
            string c = f(s.substr(0, i), s.substr(i));
            if (c.size() < res.size() || (c.size() == res.size() && c < res))
            {
                res = c;
            }
            break;
        }
    }

    cout << res << endl;

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