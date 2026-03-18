#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
const int INF = 1e9 + 7;

int a[N], c[N], nn;

inline int lowbit(int x) { return x & -x; }

void update(int x, int v)
{
    a[x] = v;
    for (int i = x; i <= nn; i += lowbit(i))
    {
        c[i] = a[i];
        for (int j = 1; j < lowbit(i); j <<= 1)
        {
            c[i] = min(c[i], c[i - j]);
        }
    }
}

int getmin(int l, int r)
{
    int ans = INF;
    while (r >= l)
    {
        ans = min(ans, a[r]);
        --r;
        for (; r - lowbit(r) >= l; r -= lowbit(r))
        {
            ans = min(ans, c[r]);
        }
    }
    return ans;
}

void solve()
{
    int q;
    cin >> nn >> q;

    for (int i = 1; i <= nn; i++)
    {
        c[i] = INF;
    }

    vector<int> nums(nn + 1);
    for (int i = 1; i <= nn; i++)
    {
        cin >> nums[i];
        update(i, nums[i]);
    }

    while (q--)
    {
        int k;
        cin >> k;
        vector<int> pos(k);

        for (int i = 0; i < k; i++)
        {
            cin >> pos[i];
            update(pos[i], INF);
        }

        cout << getmin(1, nn) << endl;

        for (int i = 0; i < k; i++)
        {
            update(pos[i], nums[pos[i]]);
        }
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