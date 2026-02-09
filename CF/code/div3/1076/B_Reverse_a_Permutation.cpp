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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != n - i)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == n - i)
                {
                    cnt--;
                    // for (int l = i, r = j; l < r; l++, r--)
                    // {
                    //     swap(a[l], a[r]);
                    // }
                    reverse(a.begin() + i, a.begin() + j + 1);
                    break;
                }
            }
        }

        if (cnt == 0)
        {
            break;
        }
    }

    for (int x : a)
    {
        cout << x << " ";
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}