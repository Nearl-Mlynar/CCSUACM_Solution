#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    int l = n, r = n;
    int cnt = 0;
    while (r != 1)
    {
        if (l <= k && k <= r)
        {
            break;
        }
        l = l / 2;
        r = r / 2 + r % 2;
        cnt++;
    }
    if (l <= k && k <= r)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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