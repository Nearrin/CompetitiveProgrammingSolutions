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
#define lp(i, a, b) for (int i = a; i <= int(b); ++i)
#define rp(i, a, b) for (int i = int(a); i >= b; --i)
#define vp(i, a) for (int i = 0; i < int(a.size()); ++i)
#define wp(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
class Reader {
  private:
    std::FILE *file;
    std::vector<char> buffer;
    char *pointer, *end;
    inline void read_file() {
        for (int i = 0;; ++i) {
            buffer.resize(buffer.size() + (1 << i));
            int t = std::fread(&buffer[0] + buffer.size() - (1 << i), 1,
                               (1 << i), file);
            if (t != (1 << i)) {
                pointer = &buffer[0];
                end = pointer + buffer.size() - (1 << i) + t;
                break;
            }
        }
    }
    inline void ignore() {
        while (pointer != end && std::isspace(*pointer))
            ++pointer;
    }

  public:
    inline Reader(std::FILE *_file) : file(_file) { read_file(); }
    inline Reader(std::string _file) : file(std::fopen(_file.c_str(), "r")) {
        read_file();
    }
    inline ~Reader() { fclose(file); }
    inline Reader &operator>>(char &a) {
        ignore();
        a = *pointer++;
        return *this;
    }
    inline Reader &operator>>(char *a) {
        ignore();
        while (pointer != end && !std::isspace(*pointer))
            *a++ = *pointer++;
        *a = 0;
        return *this;
    }
    inline Reader &operator>>(std::string &a) {
        ignore();
        while (pointer != end && !std::isspace(*pointer))
            a.push_back(*pointer++);
        return *this;
    }
    inline Reader &operator>>(int &a) {
        ignore();
        bool f = false;
        if (*pointer == '-') {
            f = true;
            ++pointer;
        }
        a = 0;
        while (pointer != end && std::isdigit(*pointer))
            a = a * 10 + *pointer++ - '0';
        if (f)
            a = -a;
        return *this;
    }
    inline Reader &operator>>(long long &a) {
        ignore();
        bool f = false;
        if (*pointer == '-') {
            f = true;
            ++pointer;
        }
        a = 0;
        while (pointer != end && std::isdigit(*pointer))
            a = a * 10 + *pointer++ - '0';
        if (f)
            a = -a;
        return *this;
    }
    template <class VAL>
    inline void ReadVector(std::vector<VAL> &a, int n = 0) {
        if (n == 0)
            *this >> n;
        for (int i = 0; i < n; ++i) {
            VAL t;
            *this >> t;
            a.push_back(t);
        }
    }
};
class Writer {
  private:
    std::FILE *file;
    std::vector<char> buffer;

  public:
    inline Writer(std::FILE *_file) : file(_file) {}
    inline Writer(std::string _file) : file(std::fopen(_file.c_str(), "w")) {}
    inline ~Writer() {
        if (!buffer.empty())
            std::fwrite(&buffer[0], 1, buffer.size(), file);
        fclose(file);
    }
    inline Writer &operator<<(char a) {
        buffer.push_back(a);
        return *this;
    }
    inline Writer &operator<<(const char *a) {
        while (*a)
            buffer.push_back(*a++);
        return *this;
    }
    inline Writer &operator<<(const std::string &a) {
        for (int i = 0; i < a.size(); ++i)
            buffer.push_back(a[i]);
        return *this;
    }
    inline Writer &operator<<(int a) {
        if (a < 0) {
            buffer.push_back('-');
            a = -a;
        }
        static char t[10];
        char *p = t;
        do {
            int b = a / 10;
            *p++ = a - b * 10 + '0';
            a = b;
        } while (a);
        while (p > t)
            buffer.push_back(*--p);
        return *this;
    }
    inline Writer &operator<<(unsigned a) {
        static char t[10];
        char *p = t;
        do {
            int b = a / 10;
            *p++ = a - b * 10 + '0';
            a = b;
        } while (a);
        while (p > t)
            buffer.push_back(*--p);
        return *this;
    }
    inline Writer &operator<<(long long a) {
        if (a < 0) {
            buffer.push_back('-');
            a = -a;
        }
        static char t[19];
        char *p = t;
        do {
            long long b = a / 10;
            *p++ = a - b * 10 + '0';
            a = b;
        } while (a);
        while (p > t)
            buffer.push_back(*--p);
        return *this;
    }
    template <class VAL>
    inline void WriteVector(const std::vector<VAL> &a, const std::string &b) {
        for (int i = 0; i < a.size(); ++i) {
            if (i != 0)
                *this << b;
            *this << a[i];
        }
    }
};

vi to[200010];
int n;
int maxk[200010], mink[200010], siz[200010];
void dfs(int u, int p, int d) {
    if (!(to[u].size() == 1 && p == 0) && to[u].size() <= 1) {
        // cout<<u<<endl;
        maxk[u] = mink[u] = 1;
        siz[u] = 1;
    } else {
        vp(i, to[u]) if (to[u][i] != p) dfs(to[u][i], u, d + 1),
            siz[u] += siz[to[u][i]];
        if (d % 2 == 1) {
            int delta = ~0u >> 1;
            vp(i, to[u]) if (to[u][i] != p) delta =
                min(delta, siz[to[u][i]] - maxk[to[u][i]]);
            maxk[u] = siz[u] - delta;
            vp(i, to[u]) if (to[u][i] != p) mink[u] += mink[to[u][i]];
            //--mink[u];
        } else {
            int delta = ~0u >> 1;
            vp(i, to[u]) if (to[u][i] != p) delta = min(delta, mink[to[u][i]]);
            mink[u] = delta;
            maxk[u] = siz[u];
            // cout<<u<<endl;
            // if(u==2)cout<<"hehe"<<endl;
            vp(i, to[u]) if (to[u][i] != p) maxk[u] -=
                siz[to[u][i]] - maxk[to[u][i]] + 1;
            ++maxk[u];
        }
        // pf("%d:%d,%d\n",u,mink[u],maxk[u]);
    }
}
int main() {
    Reader rd(stdin);
    rd >> n;
    lp(i, 1, n - 1) {
        int u, v;
        rd >> u >> v;
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs(1, 0, 1);
    // lp(i,1,n)pf("(%d %d,%d)\n",mink[i],maxk[i],siz[i]);
    pf("%d %d\n", maxk[1], mink[1]);
    return 0;
}