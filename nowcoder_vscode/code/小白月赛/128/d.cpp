#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 998244353;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> mp;
    for (auto x : a)
    {
        mp[x]++;
    }

    i64 ans = 0, temp = 1;
    i64 mx = *max_element(a.begin(), a.end());

    for (i64 i = 1; i <= mx; i++)
    {
        if (!mp.count(i) || mp[i] < 2)
        {
            break;
        }

        i64 res = 1LL * mp[i] * (mp[i] - 1) / 2 % mod;
        temp = temp * res % mod;
        ans = (ans + temp) % mod;
    }

    cout << (ans == 0 ? 1 : ans) << endl;

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
