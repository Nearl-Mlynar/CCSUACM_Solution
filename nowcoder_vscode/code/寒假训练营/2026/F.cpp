#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int a, b;
    cin >> a >> b;

    char x = '0', y = '1';

    if (a < b)
    {
        swap(x, y);
        swap(a, b);
    }

    int pos = a / (b + 1);
    int yu = a % (b + 1);

    string s = "";

    for (int i = 0; i <= b; i++)
    {
        int cnt = pos + (i < yu);
        s.append(cnt, x);
        if(i < b)
        {
            s.push_back(y);
        }
    }

    cout << s << endl;
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