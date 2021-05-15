#include <algorithm>
#include <cctype>
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
#define pf printf
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
namespace DataStructures {
template <class VAL, class CMP> class Set {
  private:
    struct node {
        inline node(const VAL &_value, node *_left, node *_right, node *_parent,
                    const bool &_black, const int &_size)
            : value(_value), left(_left), right(_right), parent(_parent),
              black(_black), size(_size) {}
        VAL value;
        node *left, *right, *parent;
        bool black;
        int size;
    } * root, *nil;
    inline void clear(node *x) {
        if (x != nil) {
            clear(x->left);
            clear(x->right);
            delete x;
        }
    }
    inline void left_rotate(node *x) {
        node *y = x->right;
        x->right = y->left;
        if (y->left != nil)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nil)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
        y->size = x->size;
        x->size = x->left->size + x->right->size + 1;
    }
    inline void right_rotate(node *x) {
        node *y = x->left;
        x->left = y->right;
        if (y->right != nil)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nil)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->right = x;
        x->parent = y;
        y->size = x->size;
        x->size = x->left->size + x->right->size + 1;
    }
    inline void insert_fixup(node *z) {
        while (!z->parent->black) {
            if (z->parent == z->parent->parent->left) {
                node *y = z->parent->parent->right;
                if (!y->black) {
                    z->parent->black = true;
                    y->black = true;
                    (z = z->parent->parent)->black = false;
                } else {
                    if (z == z->parent->right)
                        left_rotate(z = z->parent);
                    z->parent->black = true;
                    z->parent->parent->black = false;
                    right_rotate(z->parent->parent);
                }
            } else {
                node *y = z->parent->parent->left;
                if (!y->black) {
                    z->parent->black = true;
                    y->black = true;
                    (z = z->parent->parent)->black = false;
                } else {
                    if (z == z->parent->left)
                        right_rotate(z = z->parent);
                    z->parent->black = true;
                    z->parent->parent->black = false;
                    left_rotate(z->parent->parent);
                }
            }
        }
        root->black = true;
    }
    inline void erase(node *z) {
        node *y;
        for (y = z; y != nil; y = y->parent)
            --y->size;
        if (z->left == nil || z->right == nil)
            y = z;
        else {
            y = z->right;
            while (y->left != nil)
                y = y->left;
            z->value = y->value;
            y = z->right;
            while (y->left != nil) {
                --y->size;
                y = y->left;
            }
        }
        node *x = y->left == nil ? y->right : y->left;
        x->parent = y->parent;
        if (y->parent == nil)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        if (y->black)
            erase_fixup(x);
        delete y;
    }
    inline void erase_fixup(node *x) {
        while (x != root && x->black) {
            if (x == x->parent->left) {
                node *w = x->parent->right;
                if (!w->black) {
                    w->black = true;
                    x->parent->black = false;
                    left_rotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->black && w->right->black) {
                    w->black = false;
                    x = x->parent;
                } else {
                    if (w->right->black) {
                        w->left->black = true;
                        w->black = false;
                        right_rotate(w);
                        w = x->parent->right;
                    }
                    w->black = x->parent->black;
                    x->parent->black = true;
                    w->right->black = true;
                    left_rotate(x->parent);
                    x = root;
                }
            } else {
                node *w = x->parent->left;
                if (!w->black) {
                    w->black = true;
                    x->parent->black = false;
                    right_rotate(x->parent);
                    w = x->parent->left;
                }
                if (w->left->black && w->right->black) {
                    w->black = false;
                    x = x->parent;
                } else {
                    if (w->left->black) {
                        w->right->black = true;
                        w->black = false;
                        left_rotate(w);
                        w = x->parent->left;
                    }
                    w->black = x->parent->black;
                    x->parent->black = true;
                    w->left->black = true;
                    right_rotate(x->parent);
                    x = root;
                }
            }
        }
        x->black = true;
    }
    inline node *clone(node *x, node *y) {
        if (x.size == 0)
            return nil;
        node *z = new node(*x);
        z->left = clone(x->left, z);
        z->right = clone(x->right, z);
        z->parent = y;
        return z;
    }

  public:
    class Iterator {
      private:
        node *pointer;
        friend class Set;
        inline Iterator(node *_pointer) : pointer(_pointer) {}
        inline node *precursor(node *x) {
            if (x->left->size) {
                x = x->left;
                while (x->right->size)
                    x = x->right;
                return x;
            } else {
                node *y = x->parent;
                while (y->size && x == y->left) {
                    x = y;
                    y = y->parent;
                }
                return y;
            }
        }
        inline node *successor(node *x) {
            if (x->right->size) {
                x = x->right;
                while (x->left->size)
                    x = x->left;
                return x;
            } else {
                node *y = x->parent;
                while (y->size && x == y->right) {
                    x = y;
                    y = y->parent;
                }
                return y;
            }
        }

      public:
        inline Iterator() {}
        inline bool operator==(const Iterator &a) {
            return pointer == a.pointer;
        }
        inline bool operator!=(const Iterator &a) {
            return pointer != a.pointer;
        }
        inline VAL operator*() { return pointer->value; }
        inline VAL *operator->() { return &pointer->value; }
        inline Iterator &operator++() {
            pointer = successor(pointer);
            return *this;
        }
        inline Iterator operator++(int) {
            Iterator t = *this;
            pointer = successor(pointer);
            return t;
        }
        inline Iterator &operator--() {
            pointer = precursor(pointer);
            return *this;
        }
        inline Iterator operator--(int) {
            Iterator t = *this;
            pointer = precursor(pointer);
            return t;
        }
    };
    inline Set() {
        root = nil = (node *)malloc(sizeof(node));
        nil->black = true;
        nil->size = 0;
    }
    inline Set(const Set &a) {
        nil = new node(*a.nil);
        root = clone(a.root, nil);
    }
    inline ~Set() {
        clear(root);
        free(nil);
    }
    inline Set &operator=(const Set &a) {
        clear(root);
        root = clone(a.root, nil);
        return *this;
    }
    inline Iterator Begin() {
        node *z = root;
        while (z != nil && z->left != nil)
            z = z->left;
        return Iterator(z);
    }
    inline Iterator ReverseBegin() {
        node *z = root;
        while (z != nil && z->right != nil)
            z = z->right;
        return Iterator(z);
    }
    inline Iterator End() { return Iterator(nil); }
    inline Iterator ReverseEnd() { return Iterator(nil); }
    inline void Clear() {
        clear(root);
        root = nil;
    }
    inline void Insert(const VAL &a) {
        node *y = nil, *x = root;
        while (x != nil) {
            y = x;
            ++x->size;
            if (CMP()(a, x->value))
                x = x->left;
            else
                x = x->right;
        }
        node *z = new node(a, nil, nil, y, false, 1);
        if (y == nil)
            root = z;
        else if (CMP()(z->value, y->value))
            y->left = z;
        else
            y->right = z;
        insert_fixup(z);
    }
    inline void Erase(const Iterator &a) { erase(a.pointer); }
    inline void Erase(const Iterator &a, Iterator &b) {
        for (Iterator i = a; i != b; Erase(i++))
            ;
    }
    inline void Erase(const VAL &a) {
        node *z = root;
        while (true) {
            if (CMP()(a, z->value))
                z = z->left;
            else if (CMP()(z->value, a))
                z = z->right;
            else
                break;
        }
        erase(z);
    }
    inline int Count(const VAL &a) { return CountLessEqual(a) - CountLess(a); }
    inline int CountLess(const VAL &a) {
        int r = 0;
        node *z = root;
        while (z != nil) {
            if (CMP()(z->value, a)) {
                r += z->left->size + 1;
                z = z->right;
            } else
                z = z->left;
        }
        return r;
    }
    inline int CountLessEqual(const VAL &a) {
        int r = 0;
        node *z = root;
        while (z != nil) {
            if (!CMP()(a, z->value)) {
                r += z->left->size + 1;
                z = z->right;
            } else
                z = z->left;
        }
        return r;
    }
    inline int CountGreater(const VAL &a) {
        int r = 0;
        node *z = root;
        while (z != nil) {
            if (CMP()(a, z->value)) {
                r += z->right->size + 1;
                z = z->left;
            } else
                z = z->right;
        }
        return r;
    }
    inline int CountGreaterEqual(const VAL &a) {
        int r = 0;
        node *z = root;
        while (z != nil) {
            if (!CMP()(z->value, a)) {
                r += z->right->size + 1;
                z = z->left;
            } else
                z = z->right;
        }
        return r;
    }
    inline Iterator NthElement(int a) {
        node *z = root;
        while (true) {
            if (z->left->size >= a)
                z = z->left;
            else if ((z->left->size + 1) < a) {
                a -= z->left->size + 1;
                z = z->right;
            } else
                return Iterator(z);
        }
    }
    inline Iterator Precursor(const VAL &a) {
        node *z = root, *r = nil;
        while (z != nil) {
            if (CMP()(z->value, a)) {
                r = z;
                z = z->right;
            } else
                z = z->left;
        }
        return Iterator(r);
    }
    inline Iterator Successor(const VAL &a) {
        node *z = root, *r = nil;
        while (z != nil) {
            if (CMP()(a, z->value)) {
                r = z;
                z = z->left;
            } else
                z = z->right;
        }
        return Iterator(r);
    }
    inline Iterator Find(const VAL &a) {
        node *z = root, *r = nil;
        while (z != nil) {
            if (CMP()(a, z->value))
                z = z->left;
            else if (CMP()(z->value, a))
                z = z->right;
            else
                break;
        }
        return Iterator(r);
    }
    inline Iterator LowerBound(const VAL &a) {
        node *z = root, *r = nil;
        while (z != nil) {
            if (!CMP()(z->value, a)) {
                r = z;
                z = z->left;
            } else
                z = z->right;
        }
        return Iterator(r);
    }
    inline Iterator UpperBound(const VAL &a) { return Successor(a); }
    inline std::pair<Iterator, Iterator> EqualRange(const VAL &a) {
        return std::make_pair(LowerBound(a), UpperBound(a));
    }
    inline int Size() { return root->size; }
    inline bool Empty() { return root->size == 0; }
    inline VAL Front() { return *Begin(); }
    inline VAL Back() { return *ReverseBegin(); }
};
} // namespace DataStructures
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
};
int main() {
    int n;
    sf("%d", &n);
    DataStructures::Set<pair<int, int>, cmp> s[3];
    vi ans;
    lp(i, 1, n) {
        int t;
        sf("%d", &t);
        s[t % 3].Insert(mp(t, i));
    }
    // cout<<(*s[0].Begin()).first<<endl;
    if (s[0].Empty() || (*s[0].Begin()).first != 0) {
        pf("Impossible\n");
        return 0;
    }
    ans.pb(s[0].Begin()->second);
    s[0].Erase(s[0].Begin());
    int tmp = 0;
    lp(i, 1, n - 1) {
        if (s[i % 3].Empty()) {
            pf("Impossible\n");
            return 0;
        }
        DataStructures::Set<pair<int, int>, cmp>::Iterator it =
            s[i % 3].Precursor(mp(tmp + 2, 0));
        // for(DataStructures::Set<pair<int,int>,cmp>::Iterator
        // t=s[0].Begin();t!=s[0].End();++t)
        // cout<<"="<<t->first<<" "<<t->second<<endl;
        if (it == s[i % 3].End()) {
            pf("Impossible\n");
            return 0;
        }
        tmp = it->first;
        ans.pb(it->second);
        // pf("(%d,%d)\n",it->first,it->second);
        s[i % 3].Erase(it);
    }
    pf("Possible\n");
    vp(i, ans) pf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
    return 0;
}