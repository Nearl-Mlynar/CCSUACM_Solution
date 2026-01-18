#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    vector<string> a = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};

    vector<string> b = {
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"};

    vector<string> c = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"};

    int x;
    cin >> x;

    if (x >= 10)
    {
        if (x >= 20)
        {
            if (x % 10 == 0)
            {
                cout << b[x / 10 - 2] << endl;
            }
            else
            {
                cout << b[x / 10 - 2] << "-" << a[x % 10] << endl;
            }
        }
        else
        {
            cout << c[x % 10] << endl;
        }
    }
    else
    {
        cout << a[x] << endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}