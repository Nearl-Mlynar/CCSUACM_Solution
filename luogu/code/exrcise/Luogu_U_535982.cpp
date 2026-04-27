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
    string a, b;
    for (int i = 0; i < n * 2; i++)
    {
        if (i & 1)
        {
            a += 'A';
            b += 'B';
        }
        else
        {
            a += 'B';
            b += 'A';
        }
    }
    auto f = [&](string &s, string &t) -> int
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += (s[i] != t[i]);
        }
        return ans / 2;
    };
    
    cout << min(f(s, a), f(s, b)) << endl;
    return;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}