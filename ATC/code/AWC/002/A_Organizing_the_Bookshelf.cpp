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

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!mp.count(x))
        {
            mp[x] = i + 1;
        }
    }

    cout << (mp.count(k) ? mp[k] : -1) << endl;
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