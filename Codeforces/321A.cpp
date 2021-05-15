#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#define sf scanf
#define pf printf
#define ps for (;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i, a, b) for (int i = a; i <= b; ++i)
#define rp(i, a, b) for (int i = a; i >= b; --i)
#define vp(i, v) for (int i = 0; i < v.size(); ++i)
#define wp(i, v) for (int i = int(v.size() - 1); i >= 0; --i)
typedef long long ll;
using namespace std;
#include <iostream>
#include <string>
int main() {
    int a, b;
    string s;
    cin >> a >> b >> s;
    int dx = 0, dy = 0;
    vp(i, s) {
        if (s[i] == 'U')
            ++dy;
        else if (s[i] == 'D')
            --dy;
        else if (s[i] == 'L')
            --dx;
        else if (s[i] == 'R')
            ++dx;
    }
    int x = 0, y = 0;
    if (dx == 0 && dy == 0) {
        if (a == 0 && b == 0) {
            pf("Yes\n");
            return 0;
        }
    } else if (dx == 0) {
        if (a == 0 && b / dy >= 0 && b / dy * dy == b) {
            pf("Yes\n");
            return 0;
        }
    } else if (dy == 0) {
        if (b == 0 && a / dx >= 0 && a / dx * dx == a) {
            pf("Yes\n");
            return 0;
        }
    } else {
        if (b / dy >= 0 && b / dy * dy == b && a / dx >= 0 &&
            a / dx * dx == a && b / dy == a / dx) {
            pf("Yes\n");
            return 0;
        }
    }
    vp(i, s) {
        if (s[i] == 'U')
            ++y;
        else if (s[i] == 'D')
            --y;
        else if (s[i] == 'L')
            --x;
        else if (s[i] == 'R')
            ++x;
        if (dx == 0 && dy == 0) {
            if ((a - x) == 0 && (b - y) == 0) {
                pf("Yes\n");
                return 0;
            }
        } else if (dx == 0) {
            if ((a - x) == 0 && (b - y) / dy >= 0 &&
                (b - y) / dy * dy == (b - y)) {
                pf("Yes\n");
                return 0;
            }
        } else if (dy == 0) {
            if ((b - y) == 0 && (a - x) / dx >= 0 &&
                (a - x) / dx * dx == (a - x)) {
                pf("Yes\n");
                return 0;
            }
        } else {
            if ((b - y) / dy >= 0 && (b - y) / dy * dy == (b - y) &&
                (a - x) / dx >= 0 && (a - x) / dx * dx == (a - x) &&
                (b - y) / dy == (a - x) / dx) {
                pf("Yes\n");
                return 0;
            }
        }
    }
    pf("No\n");
    return 0;
}