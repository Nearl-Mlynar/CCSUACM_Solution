#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
using pairll = pair<i64, i64>;

void solve()
{
    int n;
    cin >> n;

    priority_queue<pairll, vector<pairll>, greater<pairll>> pq;

    for (int i = 0; i < n; i++)
    {
        i64 cnt, x;
        cin >> cnt >> x;
        pq.push({x, cnt});
    }

    i64 res = 0;

    while (pq.size() > 1 || pq.top().second > 1)
    {
        auto [w, c] = pq.top();
        pq.pop();

        if (c >= 2)
        {
            res += c / 2 * (2 * w);
            pq.push({2 * w, c / 2});
            if (c & 1)
            {
                pq.push({w, 1});
            }
        }
        else
        {
            auto [w2, c2] = pq.top();
            pq.pop();

            res += (w + w2);
            pq.push({w + w2, 1});
            if (c2 > 1)
            {
                pq.push({w2, c2 - 1});
            }
        }
    }

    cout << res % mod << endl;
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
