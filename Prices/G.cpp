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
const int n = 1e5 + 7;
int tl[n], tr[n], cnt0[n];
int mxn;

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

int lowbit(int x)
{
    return x & -x;
}
void update(int *t, int k, int v)
{
    while (k <= mxn)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int *t, int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }
    return res;
}

void solve()
{
    int n, q;
    while (cin >> n >> q)
    {
        mxn = n;
        for (int i = 0; i <= n + 1; i++)
        {
            tl[i] = tr[i] = cnt0[i] = 0;
        }

        int res = 0;

        for (int i = 0; i < q; i++)
        {
            int op, l, r;
            cin >> op >> l >> r;
            if (op == 1)
            {
                update(tl, l, 1);
                update(tr, r, 1);
                if (l == r)
                {
                    cnt0[l]++;
                }
                res++;
            }
            else
            {
                cout << res - (res - getsum(tl, l)) - getsum(tr, r - 1) + (r - l == 2 ? cnt0[l + 1] : 0) << endl;
            }
        }
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