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

int ios = []()
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
    string s;
    cin >> s;

    int n = s.size();
    vector<char> stk(n + 1);
    int top = -1;

    int mx = 0;
    forn(i, 0, n - 1)
    {
        if (s[i] == '(')
        {
            stk[++top] = '(';
        }
        else if (s[i] == ')')
        {
            string temp = "";
            while (top != -1 && stk[top] != '(')
            {
                temp += stk[top--];
            }
            if (top != -1)
            {
                stk[top] = '$';
            }

            reverse(temp.begin(), temp.end());

            int res = 0, cnt = 0, x = 0, sz = temp.size();
            forn(j, 0, sz - 1)
            {
                if (temp[j] == '.')
                {
                    if (j == 0)
                    {
                        x = INT_MIN;
                    }
                    else
                    {
                        while (j < sz && temp[j] == '.')
                        {
                            cnt++;
                        }
                    }

                    if (cnt >= 2)
                    {
                        x = INT_MIN;
                    }
                }
                else
                {
                    bool flag = true;
                    string t = "";
                    while (j < sz && temp[j] != '.')
                    {
                        if (temp[j] == '$')
                        {
                            flag = false;
                            break;
                        }
                        t += temp[j++];
                    }

                    x = flag ? stoi(t) : INT_MIN;
                }

                res += x;
            }

            mx = max(res, mx);
        }
        else
        {
            stk[++top] = s[i];
        }
    }

    cout << mx << endl;
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}