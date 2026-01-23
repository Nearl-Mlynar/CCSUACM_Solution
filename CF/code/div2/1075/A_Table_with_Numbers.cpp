#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, h, l;
    cin >> n >> h >> l;

    vector<int> a(n);
    vector<int> b, c;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int i = 0;

    if (l > h)
    {
        swap(l, h);
    }

    while (i < n && (a[i] <= h || a[i] <= l))
    {
        if (a[i] <= l)
        {
            b.push_back(i);
        }
        else if (a[i] <= h)
        {
            c.push_back(i);
        }
        i++;
    }

    int cnt1 = b.size(), cnt2 = c.size();

    if (cnt1 > cnt2)
    {
        cout << cnt2 + (cnt1 - cnt2) / 2 << endl;
    }
    else
    {
        cout << cnt1 << endl;
    }
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