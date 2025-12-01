#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int q;
    cin >> q;

    bool flag1 = false, flag2 = false;
    int len1 = 1, len2 = 1;
    while (q--)
    {
        int op, k;
        string x;
        cin >> op >> k >> x;

        if (op == 1)
        {
            for (char ch : x)
            {
                if (ch != 'a')
                {
                    flag1 = true;
                }
                else
                {
                    len1 += k;
                }
            }
        }
        else
        {
            for (char ch : x)
            {
                if (ch != 'a')
                {
                    flag2 = true;
                }
                else
                {
                    len2 += k;
                }
            }
        }

        if (flag2)
        {
            cout << "YES" << endl;
        }
        else if (!flag1 && len1 < len2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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