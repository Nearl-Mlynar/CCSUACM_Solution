#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <utility>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

string add(string &a, int x)
{
    int h = (a[0] - '0') * 10 + (a[1] - '0');
    int m = (a[2] - '0') * 10 + (a[3] - '0');

    int sum = h * 60 + m + x;
    sum %= (24 * 60);
    if (sum < 0)
    {
        sum += 24 * 60;
    }

    int new_h = sum / 60;
    int new_m = sum % 60;

    string b = "";
    if (new_h < 10)
    {
        b += '0';
    }
    b += to_string(new_h);
    if (new_m < 10)
    {
        b += '0';
    }
    b += to_string(new_m);

    return b;
}

bool check(string &a)
{
    return a[0] == a[3] && a[1] == a[2];
}

void solve()
{
    string s;
    int x;
    cin >> s >> x;

    s.erase(2, 1);

    int res = 0;
    unordered_set<string> hash;
    string t = s;

    while (hash.find(t) == hash.end())
    {
        hash.insert(t);
        if (check(t))
        {
            res++;
        }
        t = add(t, x);
    }

    cout << res << endl;
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