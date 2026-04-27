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

void solve()
{
    int n;
    cin >> n;
    vector<pair<i64, i64>> p(n);
    set<pair<i64, i64>> st;
    forn(i, 0, n - 1)
    {
        cin >> p[i].first >> p[i].second;
        st.insert(p[i]);
    }

    i64 x0 = p[0].first, y0 = p[0].second;
    set<pair<i64, i64>> mp;

    auto check = [&](i64 a, i64 b) -> bool
    {
        for (auto &[px, py] : p)
        {
            if (a == px || b == py || a + b == px + py || a - b == px - py)
            {
                continue;
            }
            return false;
        }
        return true;
    };

    auto f = [&](int op, i64 v)
    {
        int ff = -1;
        forn(i, 1, n - 1)
        {
            bool flag = false;
            if (op == 0)
            {
                flag = (p[i].first == v);
            }
            else if (op == 1)
            {
                flag = (p[i].second == v);
            }
            else if (op == 2)
            {
                flag = (p[i].first + p[i].second == v);
            }
            else if (op == 3)
            {
                flag = (p[i].first - p[i].second == v);
            }

            if (!flag)
            {
                ff = i;
                break;
            }
        }

        if (ff == -1)
        {
            mp.insert({x0, y0});
            return;
        }

        i64 xb = p[ff].first, yb = p[ff].second;
        i64 sb = xb + yb, db = xb - yb;

        if (op == 0)
        {
            mp.insert({v, yb});
            mp.insert({v, sb - v});
            mp.insert({v, v - db});
        }
        else if (op == 1)
        {
            mp.insert({xb, v});
            mp.insert({sb - v, v});
            mp.insert({v + db, v});
        }
        else if (op == 2)
        {
            mp.insert({xb, v - xb});
            mp.insert({v - yb, yb});
            if ((v + db) % 2 == 0)
            {
                mp.insert({(v + db) / 2, (v - db) / 2});
            }
        }
        else if (op == 3)
        {
            mp.insert({xb, xb - v});
            mp.insert({yb + v, yb});
            if ((sb + v) % 2 == 0)
            {
                mp.insert({(sb + v) / 2, (sb - v) / 2});
            }
        }
    };

    mp.insert({x0, y0});

    forn(i, 0, 3)
    {
        i64 q = (i == 0 ? x0 : (i == 1 ? y0 : (i == 2 ? x0 + y0 : x0 - y0)));
        f(i, q);
    }

    for (auto [a, b] : mp)
    {
        if (check(a, b))
        {
            cout << "YES" << endl;
            cout << a << " " << b << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}