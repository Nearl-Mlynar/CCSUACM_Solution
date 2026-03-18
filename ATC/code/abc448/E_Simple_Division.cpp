#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

i64 ksm(i64 a, i64 b, i64 p)
{
    i64 res = 1;
    a %= p;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

i64 f(i64 a, i64 n, i64 p)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        i64 cnt1 = f(a, n / 2, p);
        i64 cnt2 = ksm(a, n / 2, p);
        return (cnt1 * (1 + cnt2)) % p;
    }
    else
    {
        return (1 + (a % p) * f(a, n - 1, p)) % p;
    }
}

void solve()
{
    int k;
    i64 m;
    cin >> k >> m;

    i64 p = m * 10007LL;
    i64 x = 0;

    for (int i = 0; i < k; i++)
    {
        i64 c, l;
        cin >> c >> l;
        x = (x * ksm(10, l, p) + c * f(10, l, p)) % p;
    }

    cout << (x / m) % 10007 << endl;

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