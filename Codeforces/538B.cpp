#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define sf scanf
#define si(a) scanf("%d", &a)
#define pf printf
#define pi(a) printf("%d", a)
#define fr freopen
#define ps for (;;)
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, a) for (int i = 0; i < int(a.size()); ++i)
#define wp(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int main() {
    int n;
    cin >> n;
    stringstream ss;
    ss << n;
    string sn;
    ss >> sn;
    vector<int> ans;
    while (sn != string(sn.size(), '0')) {
        string tt = string(sn.size(), '0');
        vp(i, sn) if (sn[i] != '0') {
            --sn[i];
            ++tt[i];
        }
        stringstream ss;
        ss << tt;
        // cout<<tt<<endl;
        int ttt;
        ss >> ttt;
        // cout<<ttt<<endl;
        ans.pb(ttt);
    }
    cout << ans.size() << endl;
    vp(i, ans) cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    return 0;
}