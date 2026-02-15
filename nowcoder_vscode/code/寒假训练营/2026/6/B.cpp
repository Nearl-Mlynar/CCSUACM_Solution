#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 998244353;
const int N = 1e6 + 5;

i64 fac[N], inv[N];

i64 ksm(i64 a, i64 b)
{
    i64 r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = r * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

i64 C(int n, int k)
{
    if (n < 0 || k < 0 || k > n)
    {
        return 0;
    }
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve()
{
    int n, x, t;
    cin >> n >> x >> t;

    if (t == 0)
    {
        if (x == 0 || x == n)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }
    if (x == 0 || x == n)
    {
        cout << 0 << endl;
        return;
    }

    i64 ans = 0;
    ans = (ans + C(x - 1, (t + 2) / 2 - 1) * C(n - x - 1, (t + 1) / 2 - 1)) % mod;
    ans = (ans + C(x - 1, (t + 1) / 2 - 1) * C(n - x - 1, (t + 2) / 2 - 1)) % mod;

    cout << ans << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[N - 1] = ksm(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
