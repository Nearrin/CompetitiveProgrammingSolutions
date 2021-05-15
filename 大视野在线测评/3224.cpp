#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
 
const int MXN = 100000;
int val[MXN], siz[MXN], chd[MXN][2], fix[MXN];
int tot = 1, stk[MXN], stkSiz = 0, root = 0;
 
inline void rotate(int &x, int d) {
    int y = chd[x][!d];  chd[x][!d] = chd[y][d]; chd[y][d] = x;
    siz[y] = siz[x]; siz[x] = siz[chd[x][0]] + siz[chd[x][1]] + 1;
    x = y;
}
 
void insert(int &x,int v) {
    if (x == 0) {
        if (stkSiz != 0) x = stk[--stkSiz], chd[x][0] = chd[x][1] = 0;
        else x = tot++;
        val[x] = v; siz[x] = 1; fix[x] = std::rand();
    } else {
        int d = v > val[x]; insert(chd[x][d], v); ++siz[x];
        if (fix[chd[x][d]] < fix[x]) rotate(x, !d);
    }
}
 
void _delete(int &x,int v){
    if (v == val[x])
        if (!chd[x][0] || !chd[x][1])
            stk[stkSiz++] = x, x = chd[x][!chd[x][0]];
        else {
            int d = fix[chd[x][0]] > fix[chd[x][1]];
            rotate(x, !d); _delete(chd[x][!d], v); --siz[x];
        }
    else
        _delete(chd[x][v > val[x]], v), --siz[x];
}
 
int select(int x, int k) {
    if (k <= siz[chd[x][0]]) return select(chd[x][0], k);
    else if (k == siz[chd[x][0]] + 1) return val[x];
    else return select(chd[x][1], k - (siz[chd[x][0]] + 1));
}
 
int rank(int x, int v) {
    if (x == 0) return 1;   
    if (v <= val[x]) return rank(chd[x][0], v);
    else return rank(chd[x][1] ,v) + siz[chd[x][0]] + 1;
}
 
int pred(int x, int v) {
    if (x == 0) return -0x7fffffff;
    if (v <= val[x]) return pred(chd[x][0], v);
    else return std::max(val[x], pred(chd[x][1], v));
}
 
int succ(int x, int v) {
    if (x == 0) return 0x7fffffff;
    if (v >= val[x]) return succ(chd[x][1], v);
    else return std::min(val[x], succ(chd[x][0], v));
}
 
void print(int x) {
    if (x) {
        print(chd[x][0]);
        std::printf("[ID%d,VA%d,SZ%d,C0%d,C1%d,FX%d]\40", x, val[x], siz[x], chd[x][0], chd[x][1], fix[x]);
        print(chd[x][1]);
    }
}
 
int main() {
    //std::srand(std::time(0));;
    int n, op, v;
    std::scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        std::scanf("%d%d", &op, &v);
        switch(op) {
            case 1 : insert(root, v); break;
            case 2 : _delete(root, v); break;
            case 3 : std::printf("%d\n", rank(root, v)); break;
            case 4 : std::printf("%d\n", select(root, v)); break;
            case 5 : std::printf("%d\n", pred(root, v)); break;
            case 6 : std::printf("%d\n", succ(root, v));; break;
        }
        //std::printf("\n");
        //print(root);
        //std::printf("\n");
    }
    //system("pause");
    return 0;
}
