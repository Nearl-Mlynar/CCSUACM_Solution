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

i64 cnt[11][100];

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
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
        int sum = 0, sz = str[i].size();
        for (char c : str[i])
        {
            sum += (c - '0');
        }
        cnt[sz][sum]++;
    }

    i64 res = 0;

    for (string &s : str)
    {
        int sz = s.size();
        forn(i, 1, 5)
        {
            if ((sz + i) % 2 != 0)
            {
                continue;
            }

            int mid = (sz + i) / 2;

            if (sz >= i)
            {
                int suml1 = 0, sumr1 = 0;
                forn(k, 0, mid - 1)
                {
                    suml1 += (s[k] - '0');
                }
                forn(k, mid, sz - 1)
                {
                    sumr1 += (s[k] - '0');
                }
                int diff1 = suml1 - sumr1;
                if (diff1 > 0)
                {
                    res += cnt[i][diff1];
                }

                if (sz > i)
                {
                    int sumr2 = 0, suml2 = 0;
                    forn(k, sz - mid, sz - 1)
                    {
                        sumr2 += (s[k] - '0');
                    }
                    forn(k, 0, sz - mid - 1)
                    {
                        suml2 += (s[k] - '0');
                    }

                    int diff2 = sumr2 - suml2;
                    if (diff2 > 0)
                    {
                        res += cnt[i][diff2];
                    }
                }
            }
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