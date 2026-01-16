#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;

    if (k == 0)
    {
        cout << 1 << endl;
        return;
    }

    int cnt_r = 0, cnt_y = 0, cnt_w = 0;
    int ans = INT_MAX;

    for (int l = 0, r = 0; r < n; r++)
    {
        if (s[r] == 'r')
        {
            cnt_r++;
        }
        else if (s[r] == 'y')
        {
            cnt_y++;
        }
        else
        {
            cnt_w++;
        }

        while (l <= r)
        {
            i64 mx = max(cnt_r * 2LL + cnt_y, cnt_r + cnt_y * 2LL) + min(cnt_w, m) * 2LL;

            if (mx >= k)
            {
                ans = min(ans, r - l + 1);
                if (s[l] == 'r')
                {
                    cnt_r--;
                }
                else if (s[l] == 'y')
                {
                    cnt_y--;
                }
                else
                {
                    cnt_w--;
                }
                l++;
            }
            else
            {
                break;
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
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