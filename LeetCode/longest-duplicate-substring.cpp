#include <bits/stdc++.h>
using namespace std;
namespace rabin_karp_algorithm {
struct lowercase_letter {
    int operator()(const char &c) { return c - 'a'; }
    static const int s = 26;
};
template <class I = lowercase_letter, int M = 1073741789>
struct rabin_karp_algorithm {
    template <class S>
    rabin_karp_algorithm(const S &s) : n(s.size()), h(n + 1) {
        for (int i = 0; i < n; ++i)
            h[i + 1] = ((long long)h[i] * b + I()(s[i]) + 1) % M;
    }
    static int power(int x) {
        while (p.size() <= x)
            p.push_back((long long)p.back() * b % M);
        return p[x];
    }
    int hash(int l = 0, int r = -1) {
        if (r == -1)
            r = n - 1;
        return (h[r + 1] - (long long)h[l] * power(r - l + 1)%M + M) % M;
    }
    static pair<int, int> concatenate(const pair<int, int> &a,
                                      const pair<int, int> &b) {
        return {a.first + b.first,
                ((long long)a.second * power(b.first) +
                 b.second) %
                    M};
    }
    int n;
    static const int b;
    static mt19937_64 g;
    vector<int> h;
    static vector<int> p;
};
    template <class I,int M>mt19937_64 rabin_karp_algorithm<I,M>::g(chrono::steady_clock::now().time_since_epoch().count());
template <class I,int M>
const int rabin_karp_algorithm<I,M>::b = uniform_int_distribution<int>(I::s + 1,
                                                                   M - 1)(g);
template <class I,int M> vector<int> rabin_karp_algorithm<I,M>::p(1, 1);
} // namespace rabin_karp_algorithm
class Solution {
public:
    string longestDupSubstring(string a) {
        rabin_karp_algorithm::rabin_karp_algorithm b(a);
        rabin_karp_algorithm::rabin_karp_algorithm<rabin_karp_algorithm::lowercase_letter,int(1e9+7)>b2(a);
        auto check=[&](int x){
            set<pair<int,int>>c;
            for(int i=0;i+x<=a.size();++i){
                int h=b.hash(i,i+x-1);
                int h2=b2.hash(i,i+x-1);
                if(!c.insert({h,h2}).second)
                    return i;
            }
            return -1;
        };
        int l=1,r=a.size();
        if(check(l)==-1)
            return "";
        while(l+1<r){
            int m=(l+r)/2;
            if(check(m)==-1)r=m;
            else l=m;
        }
        return a.substr(check(l),l);
    }
};
