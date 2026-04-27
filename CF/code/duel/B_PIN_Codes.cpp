#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rforn(i, a, b) for (int i = a; i >= b; --i)
#define all(v, l, r, ...) v.begin() + l, v.begin() + r, ##__VA_ARGS__
#define rall(v, l, r, ...) v.rbegin() + l, v.rbegin() + r, ##__VA_ARGS__
#define endl '\n'

const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int fast_io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();

int init = []()
{
    return 0;
}();

void solve()
{
    int n;
    cin >> n;

    vector<string> str(n);
    set<string> st;
    map<string, vector<int>> mp;
    forn(i, 0, n - 1)
    {
        cin >> str[i];
        st.insert(str[i]);
        mp[str[i]].push_back(i);
    }

    cout << n - st.size() << endl;
    for (auto &[s, x] : mp)
    {
        if (x.size() == 1)
        {
            continue;
        }
        for (int k = 0; k < x.size() - 1; k++)
        {
            string t = s;
            bool flag = false;
            for (int i = 0; i < 4; i++)
            {
                char temp = t[i];
                for (int j = 0; j <= 9; j++)
                {
                    if (temp == '0' + j)
                    {
                        continue;
                    }
                    t[i] = '0' + j;
                    if (!st.count(t))
                    {
                        st.insert(t);
                        flag = true;
                    }
                    if (flag)
                    {
                        break;
                    }
                }
                if (flag)
                {
                    str[x[k]] = t;
                    break;
                }
            }
        }
    }

    for (string s : str)
    {
        cout << s << endl;
    }

    return;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}