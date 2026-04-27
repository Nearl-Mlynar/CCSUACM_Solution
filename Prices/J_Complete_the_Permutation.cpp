#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; i >= b; --i)
#define all(v, l, r, ...) v.begin() + l, v.begin() + r, ##__VA_ARGS__
#define rall(v, l, r, ...) v.rbegin() + l, v.rbegin() + r, ##__VA_ARGS__
#define endl '\n'

const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    forn(i, 0, n - 1)
    {
        cin >> a[i];
    }

    vector<pair<int, pair<int, int>>> range;
    for (int i = 0; i < n - 1; i++)
    {
        range.push_back({min(a[i], a[i + 1]) + 1, {max(a[i], a[i + 1]) - 1, i}});
    }

    sort(range.begin(), range.end());

    vector<int> ans(n - 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int x = 0;
    bool flag = true;

    for (int i = 2; i <= 2 * n - 2; i += 2)
    {
        while (x < n - 1 && range[x].first <= i)
        {
            pq.push(range[x].second);
            x++;
        }

        if (pq.empty() || pq.top().first < i)
        {
            flag = false;
            break;
        }

        int idx = pq.top().second;
        ans[idx] = i;
        pq.pop();
    }

    if (!flag)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int x : ans)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    return;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}