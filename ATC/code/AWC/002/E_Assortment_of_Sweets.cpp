#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, s;
    cin >> n >> s;

    vector<i64> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<i64> left(a.begin(), a.begin() + n / 2);
    vector<i64> right(a.begin() + n / 2, a.end());

    auto f = [&](vector<i64> &arr) -> vector<i64>
    {
        vector<i64> res;
        int m = arr.size();
        for (int mask = 0; mask < (1 << m); ++mask)
        {
            i64 sum = 0;
            for (int i = 0; i < m; ++i)
            {
                if (mask & (1 << i))
                {
                    sum += arr[i];
                }
            }
            res.push_back(sum);
        }
        return res;
    };

    vector<i64> left_sums = f(left);
    vector<i64> right_sums = f(right);

    sort(left_sums.begin(), left_sums.end());

    i64 ans = 0;
    for (i64 r_sum : right_sums)
    {
        auto [l, r] = equal_range(left_sums.begin(), left_sums.end(), s - r_sum);
        ans += r - l;
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