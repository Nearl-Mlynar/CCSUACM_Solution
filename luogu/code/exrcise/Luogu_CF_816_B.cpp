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
const i64 N = 2e5 + 7;

int diff[N], pre[N];
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
    int n, k, q;
    cin >> n >> k >> q;
    memset(diff, 0, sizeof diff);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        diff[l]++, diff[r + 1]--;
    }

    partial_sum(diff + 1, diff + 200001, diff + 1);

    transform(diff + 1, diff + 200001, diff + 1, [&](int x) { 
        return x >= k; 
    });

    partial_sum(diff + 1, diff + 200001, diff + 1);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << diff[r] - diff[l - 1] << '\n';
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