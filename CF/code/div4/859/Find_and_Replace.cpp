#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    string s;

    cin >> n >> s;
    vector<int> cnt(26, -1);
    for (int i = 0; i < n; i++)
    {
        if (cnt[s[i] - 'a'] != -1)
        {
            if ((i & 1) != cnt[s[i] - 'a'])
            {
                cout << "NO" << endl;
                return;
            }
        }

        cnt[s[i] - 'a'] = i & 1;
    }

    cout << "YES" << endl;
    return;
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