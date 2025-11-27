#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    double x;
    cin >> x;

    double res = 1;

    if(x < 60)
    {
        cout << "0.00" << endl;
        return;
    }


    printf("%.2f", res + ((x - 60) * 10) * 0.01);
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}