#include <bits/stdc++.h>
using namespace std;
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<int> st(a.begin(), a.end());
    vector<int> unique(st.begin(), st.end());
    int m = unique.size();

    sort(a.begin(), a.end());
    vector<int> cnt(m, 0);
    int idx = 0;
    for (int num : a)
    {
        if (num == unique[idx])
        {
            cnt[idx]++;
        }
        else
        {
            idx++;
            cnt[idx]++;
        }
    }

    int res = 0;
    int lx = -1, rx = -1;
    int l = 0;

    for (int r = 0; r < m; r++)
    {
        if (cnt[r] < k)
        {
            l = r + 1;
            continue;
        }

        if (r > 0 && unique[r] != unique[r - 1] + 1)
        {
            l = r;
        }

        if (unique[r] - unique[l] + 1 > res)
        {
            res = unique[r] - unique[l] + 1;
            lx = unique[l];
            rx = unique[r];
        }
    }

    if (res == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << lx << " " << rx << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}