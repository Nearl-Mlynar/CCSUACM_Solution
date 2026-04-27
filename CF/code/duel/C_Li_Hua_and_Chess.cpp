#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    cout << "? 1 1" << endl;
    int d1;
    cin >> d1;

    if (d1 + 1 <= n && d1 + 1 <= m)
    {
        cout << "? " << d1 + 1 << " 1" << endl;
        int d2;
        cin >> d2;

        if (d2 == d1)
        {
            cout << "? 1 " << d1 + 1 << endl;
            int d3;
            cin >> d3;
            cout << "! " << d3 + 1 << " " << d1 + 1 << endl;
        }
        else
        {
            cout << "! " << d1 + 1 << " " << d2 + 1 << endl;
        }
    }
    else if (d1 + 1 > n)
    {
        cout << "? 1 " << d1 + 1 << endl;
        int d3;
        cin >> d3;
        cout << "! " << d3 + 1 << " " << d1 + 1 << endl;
    }
    else
    {
        cout << "? " << d1 + 1 << " 1" << endl;
        int d2;
        cin >> d2;
        cout << "! " << d1 + 1 << " " << d2 + 1 << endl;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}