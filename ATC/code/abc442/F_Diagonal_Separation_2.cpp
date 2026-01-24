#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int n;
const int MAXN = (1 << 12) + 5;
int t1[MAXN][MAXN];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        for (int j = y; j <= n; j += lowbit(j))
        {
            t1[i][j] += v;
        }
    }
}

void add_(int x1, int y1, int x2, int y2, int v)
{
    add(x1, y1, v);
    add(x2 + 1, y2 + 1, v);
}

int getsum(int x, int y)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            ans += t1[i][j];
        }
    }

    return ans;
}

int getsum_(int x1, int y1, int x2, int y2)
{
    return getsum(x2, y2) - getsum(x1 - 1, y2) - getsum(x2, y1 - 1) + getsum(x1 - 1, y1 - 1);
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == '#')
            {
                add(i, j, 1);
            }
        }
    }

    int sum = getsum_(1, 1, n, n);
    int mm = min(sum, n * n - sum);
    // cout << mm << endl;
    for (int i = 1; i < n; i++)
    {
        int sum2 = getsum_(i + 1, i + 1, n, n);
        int cnt1 = sum - sum2, cnt2 = (n - i) * (n - i) - sum2;
        cout << cnt1 << " " << cnt2 << endl;
        mm = min(mm, cnt1 + cnt2);
    }

    cout << mm << endl;

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