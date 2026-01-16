#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i] % k]++;
    }

    bool flag = true;
    for (auto &[_, num] : cnt)
    {
        if (num % 2 != 0)
        {
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
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