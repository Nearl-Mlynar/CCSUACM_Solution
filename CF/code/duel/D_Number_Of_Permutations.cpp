#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; i >= b; --i)
#define all(v, l, r, ...) v.begin() + l, v.begin() + r, ##__VA_ARGS__
#define rall(v, l, r, ...) v.rbegin() + l, v.rbegin() + r, ##__VA_ARGS__
#define endl '\n'

const i64 mod = 998244353;
const i64 N = 3e5 + 7;

i64 fact[N];
map<int, int> cntA, cntB;
map<pair<int, int>, int> cntAB;

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    return 0;
}();

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> s(n);

    forn(i, 0, n - 1)
    {
        cin >> s[i].first >> s[i].second;
        cntA[s[i].first]++;
        cntB[s[i].second]++;
        cntAB[{s[i].first, s[i].second}]++;
    }

    i64 cnt1 = 1;
    for (auto &[_, x] : cntA)
    {
        cnt1 = (cnt1 * fact[x]) % mod;
    }

    i64 cnt2 = 1;
    for (auto &[_, x] : cntB)
    {
        cnt2 = (cnt2 * fact[x]) % mod;
    }

    sort(s.begin(), s.end());

    i64 cnt12 = 1;
    bool flag = true;
    forn(i, 0, n - 2)
    {
        if (s[i].second > s[i + 1].second)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        for (auto &[_, x] : cntAB)
        {
            cnt12 = (cnt12 * fact[x]) % mod;
        }
    }
    else
    {
        cnt12 = 0;
    }

    cout << ((fact[n] - cnt1 - cnt2 + cnt12) % mod + mod) % mod << endl;
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