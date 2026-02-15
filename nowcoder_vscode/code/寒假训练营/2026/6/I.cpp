#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    if (n == 3 || n == 5)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> a, b;

    for (int x = 1; x <= n; x += 6)
    {
        a.push_back(x);
    }
    for (int x = 5; x <= n; x += 6)
    {
        a.push_back(x);
    }

    for (int x = 3; x <= n; x += 6)
    {
        b.push_back(x);
    }
    for (int x = 6; x <= n; x += 6)
    {
        b.push_back(x);
    }
    for (int x = 2; x <= n; x += 6)
    {
        b.push_back(x);
    }
    for (int x = 4; x <= n; x += 6)
    {
        b.push_back(x);
    }

    vector<int> ans;

    while (b.size() >= 2)
    {
        ans.push_back(a.back());
        a.pop_back();
        ans.push_back(b.back());
        b.pop_back();
        ans.push_back(b.back());
        b.pop_back();
    }

    for (int x : ans)
    {
        cout << x << ' ';
    }
    for (int x : a)
    {
        cout << x << ' ';
    }
    for (int x : b)
    {
        cout << x << ' ';
    }
    cout << endl;

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