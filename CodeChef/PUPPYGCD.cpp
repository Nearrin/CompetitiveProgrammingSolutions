#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, long long> mp;
typedef long long ll;
long long f(int n) {
    if (mp.count(n))
        return mp[n];
    long long r = ll(n) * (n + 1) / 2;
    for (int k = 2; k <= n; ++k) {
        int t = n / k;
        int kk = n / t;
        r -= (kk - k + 1) * f(n / k);
        k = kk;
    }
    return mp[n] = r;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, d;
        scanf("%d%d", &n, &d);
        cout << f(n / d) << endl;
    }
    return 0;
}
