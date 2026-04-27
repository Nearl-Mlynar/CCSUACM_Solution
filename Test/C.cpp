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
    cin >> n;
    vector<string> str(n);

    forn(i, 0, n - 1)
    {
        cin >> str[i];
    }

    vector<pair<array<int, 26>, string>> mp(n);
    forn(i, 0, n - 1)
    {
        array<int, 26> cnt = {0};
        forn(j, 0, str[i].size() - 1)
        {
            cnt[str[i][j] - 'a']++;
        }

        mp[i] = {cnt, str[i]};
    }

    sort(mp.begin(), mp.end(), [&](auto &&a, auto &&b) {
        forn(i, 0, 25)
        {
            if(a.first[i] != b.first[i])
            {
                return a.first[i] > b.first[i];
            }
        }

        return a.second < b.second; 
    });

    forn(i, 0, n - 1)
    {
        cout << mp[i].second << ' ';
    }

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