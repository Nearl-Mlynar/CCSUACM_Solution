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
    string s;
    cin >> s;
    int n = s.size();

    string res = "";
    int l = 0, r = n - 1;

    while (r - l >= 3)
    {
        if (s[l] == s[r])
        {
            res += s[l];
            l++, r--;
        }
        else if (s[l] == s[r - 1])
        {
            res += s[l];
            l++, r -= 2;
        }
        else if (s[l + 1] == s[r])
        {
            res += s[l + 1];
            l += 2, r--;
        }
        else
        {
            res += s[l + 1];
            l += 2, r -= 2;
        }
    }

    string ans = res;
    if (l <= r)
    {
        ans += s[l];
    }
    reverse(res.begin(), res.end());

    cout << ans + res << endl;
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