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
    int n, m;
    cin >> n >> m;

    vector<string> strs(n);

    forn(i, 0, n - 1)
    {
        cin >> strs[i];
    }

    int idx = 0, mx = 0, end = 0;
    forn(i, 0, n - 1)
    {
        int cnt = 0;
        forn(j, 0, m - 1)
        {
            if (strs[i][j] == '#')
            {
                cnt++;
            }
            else
            {
                if (cnt > mx)
                {
                    mx = cnt;
                    idx = i;
                    end = j;
                }
                cnt = 0;
            }
        }

        if (cnt > mx)
        {
            mx = cnt;
            idx = i;
            end = m;
        }
    }

    cout << idx + 1 << ' ' << end - mx + (mx > 1 ? (mx + 1) / 2 : mx) << endl;
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