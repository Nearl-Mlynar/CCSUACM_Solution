#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    deque<int> mx_dq; 
    deque<int> mn_dq;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        while (!mx_dq.empty() && t[i] >= t[mx_dq.back()])
        {
            mx_dq.pop_back();
        }
        mx_dq.push_back(i);

        while (!mn_dq.empty() && t[i] <= t[mn_dq.back()])
        {
            mn_dq.pop_back();
        }
        mn_dq.push_back(i);

        while (!mx_dq.empty() && mx_dq.front() <= i - k)
        {
            mx_dq.pop_front();
        }
        while (!mn_dq.empty() && mn_dq.front() <= i - k)
        {
            mn_dq.pop_front();
        }

        if (i >= k - 1)
        {
            mx = max(mx, t[mx_dq.front()] - t[mn_dq.front()]);
        }
    }

    cout << mx << endl;
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