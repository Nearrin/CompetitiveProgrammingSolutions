#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for (;;)
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
using namespace std;
typedef long long ll;
#include <stack>
int n, m, p1[2010][2010], p2[2010][2010], p3[2010][2010], p4[2010][2010];
int sun[2010][2010];
int dir[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                 {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int vis[2010][2010];
int nw, nwr, bel[4000010], cnt[4000010];
int tr[2010][2010];
void col(int x, int y, int c) {
    sun[x][y] = c;
    lp(k, 0, 7) {
        int tx = x + dir[k][0], ty = y + dir[k][1];
        if (tx > 0 && tx <= n && ty > 0 && ty <= m && p1[tx][ty] &&
            p2[tx][ty] && !sun[tx][ty]) {
            col(tx, ty, c);
        }
    }
}
void hehe(int x, int y, int c) {
    tr[x][y] = c;
    lp(k, 0, 7) {
        int tx = x + dir[k][0], ty = y + dir[k][1];
        if (tx > 0 && tx <= n && ty > 0 && ty <= m) {
            if (sun[tx][ty])
                bel[c] = sun[tx][ty];
            else if (p1[tx][ty] && !tr[tx][ty])
                hehe(tx, ty, c);
        }
    }
}
int main() {
    sf("%d%d", &n, &m);
    lp(i, 1, n) lp(j, 1, m) sf("%d", &p1[i][j]), p2[i][j] = p1[i][j];
    lp(k, 1, 3) {
        lp(i, 1, n) lp(j, 1, m) p3[i][j] = 0;
        lp(i, 1, n) lp(j, 1, m) {
            int tmp = 1;
            lp(l, 0, 7) {
                int ti = i + dir[l][0], tj = j + dir[l][1];
                if (ti > 0 && ti <= n && tj > 0 && tj <= m) {
                    if (p2[ti][tj] == 0)
                        tmp = 0;
                }
            }
            p3[i][j] = tmp;
        }
        lp(i, 1, n) lp(j, 1, m) swap(p2[i][j], p3[i][j]);
    }
    /*lp(i,1,n){
        lp(j,1,m)pf("%d",p2[i][j]);
        pf("\n");
    }*/
    lp(k, 1, 6) {
        lp(i, 1, n) lp(j, 1, m) p3[i][j] = 0;
        lp(i, 1, n) lp(j, 1, m) {
            int tmp = 0;
            lp(l, 0, 7) {
                int ti = i + dir[l][0], tj = j + dir[l][1];
                if (ti > 0 && ti <= n && tj > 0 && tj <= m) {
                    if (p2[ti][tj] == 1)
                        tmp = 1;
                }
            }
            p3[i][j] = tmp;
        }
        lp(i, 1, n) lp(j, 1, m) swap(p2[i][j], p3[i][j]);
    }
    /*lp(i,1,n){
        lp(j,1,m)pf("%d",int(p2[i][j]==0&&p1[i][j]==1));
        pf("\n");
    }*/
    lp(i, 1, n) lp(j, 1, m) if (p1[i][j] && p2[i][j] && !sun[i][j])
        col(i, j, ++nw);
    /*lp(i,1,n){
        lp(j,1,m)pf("%d",sun[i][j]);
        pf("\n");
    }*/
    lp(i, 1, n) lp(j, 1, m) if (p1[i][j] && !sun[i][j] && !tr[i][j])
        hehe(i, j, ++nwr);
    /*lp(i,1,n){
        lp(j,1,m)pf("%d",bel[tr[i][j]]);
        pf("\n");
    }*/
    lp(i, 1, nwr)++ cnt[bel[i]];
    vector<int> huhu;
    lp(i, 1, nw) huhu.pb(cnt[i]);
    sort(huhu.begin(), huhu.end());
    pf("%d\n", nw);
    vp(i, huhu) pf("%d%c", huhu[i], i + 1 == huhu.size() ? '\n' : ' ');
    // ps;
    return 0;
}
/*
10 10
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 1 0 0 0
0 0 0 0 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/