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
const int LOG = 20;

int a[N];
int st[LOG][N];
int lg2[N];

int init = []()
{
    lg2[1] = 0;
    for (int i = 2; i < N; i++)
    {
        lg2[i] = lg2[i / 2] + 1;
    }
    return 0;
}();

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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        st[0][i] = a[i];
    }
    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = st[j - 1][i] & st[j - 1][i + (1 << (j - 1))];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, k;
        cin >> l >> k;

        auto check = [&](int m) -> bool
        {
            int lg = lg2[m - l + 1];
            int res = st[lg][l] & st[lg][m - (1 << lg) + 1];
            return res >= k;
        };

        if (!check(l))
        {
            cout << -1 << ' ';
            continue;
        }

        int left = l, right = n + 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        cout << left << ' ';
    }
    cout << endl;
    return;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}