#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MXN = 100003;
int val[MXN], siz[MXN], prt[MXN], chd[MXN][2];
bool rev[MXN];
int sam[MXN], sum[MXN], mxL[MXN], mxR[MXN], mxM[MXN];
int queSiz = 1, stk[MXN], stkSiz = 0, root = 0;

int a[100002], n, m;

inline void pushUp(int x) { // 维护自底向上的标记。 
    siz[x] = siz[chd[x][0]] + siz[chd[x][1]] + 1;
}

inline void pushDown(int x) { // 维护自顶向下的标记。 
    if (rev[x]) {
        rev[chd[x][0]] = !rev[chd[x][0]];
        rev[chd[x][1]] = !rev[chd[x][1]];
        std::swap(chd[x][0], chd[x][1]);
        rev[x] = false;
    }
}

inline void rotate(int x, int d) {
    int y = prt[x], z = prt[y];
    pushDown(y); pushDown(x);
    chd[y][!d] = chd[x][d]; prt[chd[x][d]] = y; // 维护 y 和 x 的孩子的关系。 
    prt[x] = z; chd[z][y != chd[z][0]] = x; // 维护 x 和 z的关系 
    prt[y] = x; chd[x][d] = y;// 维护 x 和 y 的关系。 
    pushUp(y);
}

void splay(int x, int p) { // 把 x 伸展到 p 的下面。 
    while (prt[x] != p) {
        int y = prt[x], z = prt[y];
        /*
        if (z == p) rotate(x, chd[y][0] == x); // 单旋。 
        else
            if (y == chd[z][0])
                if (x == chd[y][0]) rotate(y, 1), rotate(x, 1); //  一字旋转。 
                else rotate(x, 0), rotate(x, 1); // 之字旋转。 
            else
                if (x == chd[y][1]) rotate(y, 0), rotate(x, 0); //  一字旋转。       
                else rotate(x, 1), rotate(x, 0); // 之字旋转。 
        */
        rotate(x, chd[y][0] == x);
    }
    pushUp(x); // 最后对 x 进行维护，减少对 x 的多余维护。 
    if (p == 0) root = x;
}

void select(int k, int p) { // 把第 k 个元素伸展到 p 的下面。 
    int x = root;
    while (true) {
        pushDown(x); // 要先维护 x ，因为 x 的左孩子的 siz 可能改变。 
        if (k == siz[chd[x][0]] + 1) break;
        if (k < siz[chd[x][0]] + 1)  x = chd[x][0];
        else k -= siz[chd[x][0]] + 1, x = chd[x][1];
    }
    splay(x, p);
}


void reverse(int l, int r) {
    select(l - 1, 0); select(r + 1, root);
    rev[chd[chd[root][1]][0]] = !rev[chd[chd[root][1]][0]];
    splay(chd[chd[root][1]][0], 0);
}

void build(int &x, int *l, int *r) {
    if (l > r) x = 0;
    else {
        int *m = l + ((r - l) >> 1);
        x = queSiz++;
        val[x] = *m; siz[x] = 1;
        build(chd[x][0], l, m - 1); build(chd[x][1], m + 1, r);
        prt[chd[x][0]] = prt[chd[x][1]] = x;
        pushUp(x);
    }
}  

void print(int x) {
    if (x != 0) {
        pushDown(x);
        print(chd[x][0]);
        printf("%d\40", val[x]);
        print(chd[x][1]);
        if (x == root)
            printf("\n");
    }
}


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; ++i)
        a[i] = i;
    build(root, a, a + n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        reverse(l + 1, r + 1);
    }
    select(1, 0);
    select(n + 2, root);
    print(chd[chd[root][1]][0]);
    //system("pause");
    return 0;
}
