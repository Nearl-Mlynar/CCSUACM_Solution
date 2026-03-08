#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
#define i64 long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    i64 res = 0;
    deque<int> mxq, mnq;

    for (int l = 0, r = 0; r < n; r++)
    {
        while (!mxq.empty() && a[mxq.back()] <= a[r])
        {
            mxq.pop_back();
        }
        mxq.push_back(r);

        while (!mnq.empty() && a[mnq.back()] >= a[r])
        {
            mnq.pop_back();
        }
        mnq.push_back(r);

        while (!mxq.empty() && !mnq.empty() && a[mxq.front()] - a[mnq.front()] > 1)
        {
            l++;
            if (mxq.front() < l)
            {
                mxq.pop_front();
            }
            if (mnq.front() < l)
            {
                mnq.pop_front();
            }
        }

        res += (r - l + 1);
    }

    cout << res << endl;

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