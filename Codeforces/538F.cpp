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

class PersistentIntSet {
  private:
    struct node {
        inline node(node *_lc, node *_rc, const int &_siz)
            : lc(_lc), rc(_rc), siz(_siz) {}
        node *lc, *rc;
        int siz;
    };
    int delta, maxl;
    inline int size(node *x) { return x ? x->siz : 0; }
    inline node *insert(node *x, const int &v, const int &d) {
        if (d < 0)
            return new node(0, 0, x->siz + 1);
        if (v >> d & 1) {
            if (x->rc)
                return new node(x->lc, insert(x->rc, v, d - 1), x->siz + 1);
            else {
                x = new node(x->lc, new node(0, 0, 1), x->siz + 1);
                node *y = x->rc;
                for (int i = d - 1; i >= 0; --i)
                    if (v >> i & 1)
                        y = y->rc = new node(0, 0, 1);
                    else
                        y = y->lc = new node(0, 0, 1);
                return x;
            }
        } else {
            if (x->lc)
                return new node(insert(x->lc, v, d - 1), x->rc, x->siz + 1);
            else {
                x = new node(new node(0, 0, 1), x->rc, x->siz + 1);
                node *y = x->lc;
                for (int i = d - 1; i >= 0; --i)
                    if (v >> i & 1)
                        y = y->rc = new node(0, 0, 1);
                    else
                        y = y->lc = new node(0, 0, 1);
                return x;
            }
        }
    }
    inline node *erase(node *x, const int &v, const int &d) {
        if (d < 0)
            return 0;
        if (v >> d & 1)
            return new node(x->lc, insert(x->rc, v, d - 1), x->siz - 1);
        else
            return new node(insert(x->lc, v, d - 1), x->rc, x->siz - 1);
    }

  public:
    class Pointer {
      private:
        node *p;
        friend class PersistentIntSet;

      public:
        inline Pointer(node *_p = new node(0, 0, 0)) : p(_p) {}
    };
    inline PersistentIntSet(const int &a, int b) : delta(a), maxl(0) {
        b -= a;
        for (; b; b >>= 1)
            ++maxl;
    }
    inline Pointer Insert(const Pointer &a, const int &b) {
        return Pointer(insert(a.p, b - delta, maxl - 1));
    }
    inline Pointer Erase(const Pointer &a, const int &b) {
        return Pointer(erase(a.p, b - delta, maxl - 1));
    }
    inline int Count(const Pointer &a, const int &b) {
        node *x = a.p;
        for (int i = maxl - 1; i >= 0; --i) {
            if ((b - delta) >> i & 1) {
                if (x->rc)
                    x = x->rc;
                else
                    return 0;
            } else {
                if (x->lc)
                    x = x->lc;
                else
                    return 0;
            }
        }
        return x->siz;
    }
    inline int CountLess(const Pointer &a, const int &b) {
        int r = 0;
        node *x = a.p;
        for (int i = maxl - 1; i >= 0; --i) {
            if ((b - delta) >> i & 1) {
                if (x->rc) {
                    r += size(x->lc);
                    x = x->rc;
                } else
                    return r;
            } else {
                if (x->lc)
                    x = x->lc;
                else
                    return r;
            }
        }
        return r;
    }
    inline int CountLessEqual(const Pointer &a, const int &b) {
        int r = 0;
        node *x = a.p;
        for (int i = maxl - 1; i >= 0; --i) {
            if ((b - delta) >> i & 1) {
                if (x->rc) {
                    r += size(x->lc);
                    x = x->rc;
                } else
                    return r;
            } else {
                if (x->lc)
                    x = x->lc;
                else
                    return r;
            }
        }
        return r + x->siz;
    }
    inline int CountGreater(const Pointer &a, const int &b) {
        int r = 0;
        node *x = a.p;
        for (int i = maxl - 1; i >= 0; --i) {
            if ((b - delta) >> i & 1) {
                if (x->rc)
                    x = x->rc;
                else
                    return r;
            } else {
                if (x->lc) {
                    r += size(x->rc);
                    x = x->lc;
                } else
                    return r;
            }
        }
        return r;
    }
    inline int CountGreaterEqual(const Pointer &a, const int &b) {
        int r = 0;
        node *x = a.p;
        for (int i = maxl - 1; i >= 0; --i) {
            if ((b - delta) >> i & 1) {
                if (x->rc)
                    x = x->rc;
                else
                    return r;
            } else {
                if (x->lc) {
                    r += size(x->rc);
                    x = x->lc;
                } else
                    return r;
            }
        }
        return r + x->siz;
    }
    inline int NthElement(const Pointer &a, int b) {
        int r = 0;
        node *x = a.p;
        for (int i = maxl - 1; i >= 0; --i) {
            if (size(x->lc) >= b)
                x = x->lc;
            else {
                b -= size(x->lc);
                r += 1 << i;
                x = x->rc;
            }
        }
        return r + delta;
    }
    inline int Size(const Pointer &a) { return size(a.p); }
};

template <class VAL, class CMP = std::less<VAL>>
std::vector<int> Discretize(const std::vector<VAL> &a) {
    std::vector<VAL> b = a;
    std::vector<int> r(a.size());
    std::sort(b.begin(), b.end(), CMP());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < r.size(); ++i)
        r[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    return r;
}

int main() {
    static PersistentIntSet::Pointer ptrs[200010];
    int n;
    sf("%d", &n);
    vector<int> a(n);
    lp(i, 0, n - 1) sf("%d", &a[i]);
    a = Discretize(a);
    PersistentIntSet st(0, n - 1);
    lp(i, 1, n) {
        // pf("[%d\n",a[i]);
        ptrs[i] = st.Insert(ptrs[i - 1], a[i - 1]);
        // st.ptree(ptrs[i]);
        // pf("%d]\n",a[i]);
    }
    // cout<<st.Size(ptrs[4])<<endl;
    // lp(i,1,5)
    // st.ptree(ptrs[i]);
    // cout<<st.CountLess(ptrs[4],171)<<endl;ps;
    lp(k, 1, n - 1) {
        int ans = 0;
        lp(v, 1, n) {
            int l = k * (v - 1) + 2, r = min(k * v + 1, n);
            if (l > n)
                break;

            ans += st.CountLess(ptrs[r], a[v - 1]) -
                   st.CountLess(ptrs[l - 1], a[v - 1]);
            // if(k==1)cout<<ans<<endl;
            // cout<<ans<<endl;
        }
        pf("%d", ans);
        if (k == n - 1)
            pf("\n");
        else
            pf(" ");
    }
    return 0;
}