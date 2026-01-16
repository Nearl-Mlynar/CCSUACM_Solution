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
    queue<int> A, B, C;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % 4 == 0)
        {
            A.push(i);
        }
        else if (x % 2 == 0)
        {
            B.push(i);
        }
        else
        {
            C.push(i);
        }
    }

    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }

    int p, pre;
    auto f = [&]() -> void
    {
        while (A.size())
        {
            cout << pre << ' ' << A.front() << endl;
            pre = A.front();
            A.pop();
        }
        while (B.size())
        {
            cout << pre << ' ' << B.front() << endl;
            pre = B.front();
            B.pop();
        }
        return;
    };

    if (C.empty())
    {
        if (!A.empty())
        {
            p = pre = A.front();
            A.pop();
        }
        else
        {
            p = pre = B.front();
            B.pop();
        }

        cout << p << endl;
        f();

        return;
    }

    p = pre = C.front();
    C.pop();

    if (A.empty())
    {
        cout << "-1" << endl;
        return;
    }

    vector<array<int, 2>> ans;

    bool flag = true;
    while (!C.empty())
    {
        if (!C.empty() && A.empty())
        {
            cout << "-1\n";
            return;
        }

        ans.push_back({pre, A.front()});
        pre = A.front();
        A.pop();

        int t;
        flag = true;
        for (int i = 1; i <= k; i++)
        {
            if (C.empty())
            {
                flag = false;
                break;
            }

            t = C.front();
            ans.push_back({pre, t});
            C.pop();
        }
        if (flag)
        {
            pre = t;
        }
    }

    if (flag && A.empty() && !B.empty())
    {
        cout << "-1" << endl;
        return;
    }

    cout << p << endl;
    for (array<int, 2> &p : ans)
    {
        cout << p[0] << ' ' << p[1] << endl;
    }
    f();
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