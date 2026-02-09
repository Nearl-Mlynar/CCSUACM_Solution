#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        long long n;
        cin >> n;
        vector<int> v;
        int pos2 = -1;
        while (n > 0)
        {
            v.push_back(n % 3);
            if (v.back() == 2)
            {
                pos2 = int(v.size()) - 1;
            }
            n /= 3;
        }
        v.push_back(0);
        if (pos2 != -1)
        {
            int pos0 = find(v.begin() + pos2, v.end(), 0) - v.begin();
            v[pos0] = 1;
            for (int i = pos0 - 1; i >= 0; --i)
            {
                v[i] = 0;
            }
        }
        i64 ans = 0;
        i64 pw = 1;
        for (int i = 0; i < int(v.size()); ++i)
        {
            ans += pw * v[i];
            pw *= 3;
        }
        if (v.back() == 1)
        {
            ans = pw / 3;
        }
        cout << ans << endl;
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