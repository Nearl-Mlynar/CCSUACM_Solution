#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, m, z;
    cin >> m >> n >> z;

    if (m >= z || (z - m) % (n + m) == 0)
    {
        cout << 0;
        return;
    }

    cout << (n >= (z - m) % (n + m) ? 1 : 0);
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}