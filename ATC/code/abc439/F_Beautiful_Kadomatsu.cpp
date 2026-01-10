#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 998244353;
const i64 N = 300007;

i64 t[N], al[N], ar[N], a[N];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, i64 v)
{
    while (k < N)
    {
        t[k] = (t[k] + v) % mod;
        k += lowbit(k);
    }
}

i64 getsum(int k)
{
    i64 res = 0;
    while (k > 0)
    {
        res = (res + t[k]) % mod;
        k -= lowbit(k);
    }

    return res;
}

void clear()
{
    for (int i = 0; i < N; i++)
    {
        t[i] = 0;
    }
}

void solve()
{
    int n;
    cin >> n;

    i64 res = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        al[i] = getsum(a[i]);
        update(a[i], 1);
    }

    clear();

    for (int i = n - 1; i >= 0; i--)
    {
        ar[i] = getsum(a[i]);
        update(a[i], 1);
    }

    for (int i = 0; i < n; i++)
    {
        ans = (ans + (res + al[i]) * ar[i]) % mod;
        res = (res * 2 + al[i]) % mod;
    }

    cout << ans << endl;
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