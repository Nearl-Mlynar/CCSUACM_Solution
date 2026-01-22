#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    string s;
    cin >> s;
    vector<int> r;
    for (string t : {"twone", "one", "two"})
    {
        for (size_t pos = 0; (pos = s.find(t, pos)) != string::npos;)
        {
            s[pos + t.length() / 2] = '?';
            r.push_back(pos + t.length() / 2);
        }
    }
    cout << r.size() << endl;
    for (auto rr : r)
    {
        cout << rr + 1 << " ";
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