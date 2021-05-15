#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        static char a[int(1e6) + 1];
        scanf("%d%d%s", &n, &k, a);
        vector<int> f(k);
        int count = 0;
        for (int i = 0; i < n; ++i)
            count += a[i] - '0';
        int answer = count;
        for (int i = 0; i < n; ++i) {
            f[i % k] = min(f[i % k], 0) + (a[i] == '0' ? 1 : -1);
            answer = min(answer, f[i % k] + count);
        }
        printf("%d\n", answer);
    }
    return 0;
}
