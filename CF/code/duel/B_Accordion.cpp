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
const i64 N = 5e5 + 7;
char stk[N];

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

    int l1 = 0;
    while (l1 < n && s[l1] != '[')
    {
        l1++;
    }
    if (l1 == n)
    {
        cout << -1 << endl;
        return;
    }

    int l2 = l1 + 1;
    while (l2 < n && s[l2] != ':')
    {
        l2++;
    }
    if (l2 == n)
    {
        cout << -1 << endl;
        return;
    }

    int r1 = n - 1;
    while (r1 >= 0 && s[r1] != ']')
    {
        r1--;
    }
    if (r1 <= l2)
    {
        cout << -1 << endl;
        return;
    }

    int r2 = r1 - 1;
    while (r2 > l2 && s[r2] != ':')
    {
        r2--;
    }
    if (r2 <= l2)
    {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    for (int i = l2 + 1; i < r2; i++)
    {
        if (s[i] == '|')
        {
            cnt++;
        }
    }

    cout << 4 + cnt << endl;
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