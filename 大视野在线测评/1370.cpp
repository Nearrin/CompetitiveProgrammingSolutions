#include <iostream>
#define For(a, b) for(int i = a; i <= b; ++i)
 
using namespace std;
 
const int MXN = 1010;
int prt[MXN], rank[MXN];
int e[MXN], ans;
 
void make(int x) {
    prt[x] = x;
}
 
int find(int x) {
    if (x != prt[x]) prt[x] = find(prt[x]);
    return prt[x];
}
 
void _union(int x, int y) {
    if (x == 0 || y == 0) return;
    x = find(x); y = find(y);
    if (x == y) return;
    --ans;
    if (rank[x] > rank[y]) prt[y] = x;
    else prt[x] = y;
    if (rank[x] == rank[y]) ++rank[y];
}
 
int main() {
    int n, m, b, c;
    char a;
    cin >> n >> m;
    ans = n;
    For(1, n) make(i);
    For(1, m) {
        cin >> a >> b >> c;
        if(a == 'F')
            _union(b, c);
        else {
            _union(e[c], b);
            e[c] = b;
            _union(e[b], c);
            e[b] = c;
        }
    }
    cout << ans << endl;
    return 0;
}
