#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

i64 t[N];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k < N)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

i64 getsum(int k)
{
    i64 res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }

    return res;
}

i64 query(int l, int r)
{
    return getsum(r) - getsum(l - 1);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            update(x, a[x + 1] - a[x]);
            update(x + 1, a[x] - a[x + 1]);
            swap(a[x], a[x + 1]);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            cout << query(l, r) << endl;
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}