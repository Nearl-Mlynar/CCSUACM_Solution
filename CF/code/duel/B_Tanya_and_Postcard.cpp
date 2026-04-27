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
    string a, b;
    cin >> a >> b;

    map<char, int> mp;

    for (char x : b)
    {
        mp[x]++;
    }

    int cnt0 = 0, cnt1 = 0;
    int n = a.size();
    vector<bool> vis(n + 1);
    for (int i = 0; i < n; i++)
    {
        char x = a[i];
        if (mp.count(x))
        {
            mp[x]--;
            vis[i] = true;
            if (mp[x] == 0)
            {
                mp.erase(x);
            }
            cnt0++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(vis[i])
        {
            continue;
        }
        char x = a[i];
        if (x >= 'a' && x <= 'z' && mp.count(toupper(x)))
        {
            mp[toupper(x)]--;
            if (mp[toupper(x)] == 0)
            {
                mp.erase(toupper(x));
            }
            cnt1++;
        }
        else if (x >= 'A' && x <= 'Z' && mp.count(tolower(x)))
        {
            mp[tolower(x)]--;
            if (mp[tolower(x)] == 0)
            {
                mp.erase(tolower(x));
            }
            cnt1++;
        }
    }

    cout << cnt0 << ' ' << cnt1 << endl;
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