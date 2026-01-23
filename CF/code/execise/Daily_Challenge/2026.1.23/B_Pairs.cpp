#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> nums(m);
    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        nums[i] = {x - 1, y - 1};
    }

    vector<int> v = {nums[0].first, nums[0].second};

    for (int x : v)
    {
        vector<int> cnt(n);
        int res = 0;

        for (auto &[a, b] : nums)
        {
            if (a != x && b != x)
            {
                cnt[a]++;
                cnt[b]++;
                res++;
            }
        }

        if (*max_element(cnt.begin(), cnt.end()) == res)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;

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