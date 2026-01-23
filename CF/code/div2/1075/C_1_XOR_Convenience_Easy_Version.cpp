#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n;
    cin >> n;
    i64 res = (1 + n) * n / 2;
    vector<i64> ans;

    for (i64 i = 2; i <= n - 1; i++)
    {
        int x = i ^ 1;
        res -= x;
        ans.push_back(x);
    }

    cout << res - 1 << " ";

    for (i64 x : ans)
    {
        cout << x << " ";
    }

    cout << 1 << endl;
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