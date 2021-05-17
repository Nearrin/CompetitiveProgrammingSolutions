#ifdef LOCAL
#include <header.hpp>
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#endif
#define lp(i, l, r) for (auto i = regu(l); i <= decltype(i)(r); ++i)
#define rp(i, r, l) for (auto i = regu(r); i >= decltype(i)(l); --i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
#define rv(i, a) for (int i = int(a.size()) - 1; i >= 0; --i)
#define lm(i, m) for (auto i = m; i; i = (m) & (i - 1))
#define many for (int C = 1, T = -1; T < 0 && cin >> T, C <= T; ++C)
#define goog "Case #" + to_string(C) + ":"
#define rang(a) begin(a), end(a)
#define elif else if
#ifndef LOCAL
#define endl '\n'
#undef assert
#define assert
#endif
using namespace std;
using namespace __gnu_pbds;
const auto eps = 1e-8, pi = M_PI;
int comp(const double&a,const double&b){
    return a<b-eps?-1:(a>b+eps);
}
#if __cplusplus > 201103L
template <class T> auto regu(const T &a) { return int(a); }
template <> auto regu(const int64_t &a) { return a; }
template <> auto regu(const uint64_t &a) { return int64_t(a); }
#else
template <class T> int64_t regu(const T &a) { return a; }
template <> int64_t regu(const uint32_t &a) { return int(a); }
#endif
template <class T> int barr(const T &a, const int &i) { return a >> i & 1; }
template <class T> int bcnt(const T &a) { return __builtin_popcount(a); }
template <> int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T rint(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b)
                                 : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b)
                                 : -abs(a) / abs(b);
}
template <class T> bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
#if __cplusplus > 201103L
template <class T> auto min(const T &a) { return *min_element(rang(a)); }
template <class T> auto max(const T &a) { return *max_element(rang(a)); }
template <class T> auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
template <> auto sum(const vector<string> &a) {
    return accumulate(rang(a), string());
}
template <class C, class V> auto find(C &c, const V &v) {
    return find(rang(c), v);
}
template <class C, class V> auto find(const C &c, const V &v) {
    return find(rang(c), v);
}
#endif
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
template <class T> void reve(T &a) { reverse(rang(a)); }
template <class T> void shuf(T &a) { shuffle(rang(a), rng); }
template <class T> void merg(T l, T m, T r) { inplace_merge(l, m, r); }
#if __cplusplus > 201103L
template <class T> auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
#endif
template <class T> double x(const complex<T> &a) { return a.real(); }
template <class T> double y(const complex<T> &a) { return a.imag(); }
template <class T> complex<T> rota(const complex<T> &p, const T &t) {
    return p * complex<T>(polar(1., -t));
}
template <class T>
complex<T> rota(const complex<T> &p, const complex<T> &a, const T &t) {
    return (p - a) * complex<T>(polar(1., -t)) + a;
}
template <class T>
complex<T> squa_dist(const complex<T> &a, const complex<T> &b) {
    return norm(a - b);
}
template <class T> T dist(const complex<T> &a, const complex<T> &b) {
    return abs(a - b);
}
template <class T> T dot(const complex<T> &a, const complex<T> &b) {
    return x(conj(a) * b);
}
template <class T> T cros(const complex<T> &a, const complex<T> &b) {
    return y(conj(a) * b);
}
template <class T>
T angl(const complex<T> &a, const complex<T> &b, const complex<T> &c) {
    return abs(remain_der(arg(a - b) - arg(c - b), 2 * pi));
}
template <class T>
complex<T> inte(const complex<T> &a, const complex<T> &b, const complex<T> &c,
                const complex<T> &d) {
    T u = cros(c - a, b - a), v = cros(d - a, b - a);
    return (u * d - v * c) / (u - v);
}
template <class T> complex<T> proj(const complex<T> &p, const complex<T> &a) {
    return a * dot(p, a) / norm(a);
}
template <class T>
complex<T> proj(const complex<T> &p, const complex<T> &a, const complex<T> &b) {
    return a + (b - a) * dot(p - a, b - a) / norm(b - a);
}
template <class T>
complex<T> refl(const complex<T> &p, const complex<T> &a, const complex<T> &b) {
    return a + conj((p - a) / (b - a)) * (b - a);
}

template <class T> int comp(const complex<T> &a, const complex<T> &b){
    int t=comp(x(a),x(b));
    if(t)return t;
    return comp(y(a),y(b));
}
template <class T>
struct less<complex<T>>{
    bool operator()(const complex<T> &a, const complex<T> &b) const{
        return comp(a,b)<0;
    }
};
template <class T> istream &operator>>(istream &s, complex<T> &a) {
    T x, y;
    return s >> x >> y, a.real(x), a.imag(y), s;
}
template <class T> ostream &operator<<(ostream &s, const complex<T> &a) {
    return s << x(a) << " " << y(a);
}
template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << a.first << " " << a.second;
}
template <class T> istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
template <class T> ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
template <class T> T in() {
    T a;
    cin >> a;
    return a;
}
template <class T> void in(T &a) { cin >> a; }
template <class A, class... B> void in(A &a, B &... b) { cin >> a, in(b...); }
void ou() { cout << endl; }
template <class T> void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
void yep(const bool &a) { ou(a ? "yes" : "no"); }
void Yep(const bool &a) { ou(a ? "Yes" : "No"); }
void YEP(const bool &a) { ou(a ? "YES" : "NO"); }
template <class T> struct hash_safe {};
template <> struct hash_safe<int> {
    size_t operator()(uint64_t a) const {
        static uint64_t d =
            chrono::steady_clock::now().time_since_epoch().count();
        a += d + 0x9e3779b97f4a7c15, a = (a ^ (a >> 30)) * 0xbf58476d1ce4e5b9;
        a = (a ^ (a >> 27)) * 0x94d049bb133111eb;
        return a ^ (a >> 31);
    }
};
template <> struct hash_safe<int64_t> {
    size_t operator()(uint64_t a) const { return hash_safe<int>()(a); }
};
template <class A, class B> struct hash_safe<pair<A, B>> {
    size_t operator()(pair<A, B> a) const {
        auto h = hash_safe<A>()(a.first), g = hash_safe<B>()(a.second);
        return (h >> 16 << 16) + (g >> 16);
    }
};
template <class T> using unordered_set_safe = unordered_set<T, hash_safe<T>>;
template <class T>
using unordered_multiset_safe = unordered_multiset<T, hash_safe<T>>;
template <class K, class V>
using unordered_map_safe = unordered_map<K, V, hash_safe<K>>;
template <class K, class V>
using unordered_multimap_safe = unordered_multimap<K, V, hash_safe<K>>;
#define unordered_set unordered_set_safe
#define unordered_multiset unordered_multiset_safe
#define unordered_map unordered_map_safe
#define unordered_multimap unordered_multimap_safe
template <class T, class C = less<T>>
using bbst =
    tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = greater<T>>
using heap = __gnu_pbds::priority_queue<T, C, pairing_heap_tag>;
using ll = int64_t;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pt = complex<double>;
using vi = vector<int>;
using vl = vector<ll>;
using vai = valarray<int>;
using val = valarray<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
int main_() {
    ios::sync_with_stdio(!cin.tie(0));
    cout << setprecision(16) << fixed;
    return 0;
}
vector<pt>solve(pt v,pt pm,pt p1,double r){
    double a=x(v)*x(v)+y(v)*y(v);
    double b=2*(x(v)*(x(pm)-x(p1))+y(v)*(y(pm)-y(p1)));
    double c=(x(pm)-x(p1))*(x(pm)-x(p1))+(y(pm)-y(p1))*(y(pm)-y(p1))-r*r;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    double t1=(-b+sqrt(b*b-4*a*c))/2/a;
    double t2=(-b-sqrt(b*b-4*a*c))/2/a;
    return {{x(pm)+x(v)*t1,y(pm)+y(v)*t1},{x(pm)+x(v)*t2,y(pm)+y(v)*t2}};
}
class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        map<pt,int>count;
        for(auto i:points)
            ++count[{i[0]*1.,i[1]*1.}];
        int ans=0;
        for(auto i:count)
            ans=max(ans,i.second);
        for(auto i:count)for(auto j:count){
            //cout<<i.first.first<<" "<<i.first.second<<endl;
            //cout<<j.first.first<<" "<<j.first.second<<endl;
            //cout<<int(i.first!=j.first)<<endl;
            if(comp(i.first,j.first)){
                auto p1=i.first;
                auto p2=j.first;
                if(comp(dist(p1,p2),4*r*r)<1){
                    //cout<<p1.first<<" "<<p1.second<<endl;
                    //cout<<p2.first<<" "<<p2.second<<endl;
                    auto pm=(p1+p2)/2.;
                    //cout<<pm.first<<" "<<pm.second<<endl;
                    auto v=rota(p1-p2,pi/2);
                    //cout<<v.first<<" "<<v.second<<endl;
                    for(auto center:solve(v,pm,p1,r)){
                        //cout<<center.first<<" "<<center.second<<endl;
                        int cur=0;
                        for(auto k:count)if(dist(center,k.first)<=r+1e-8)
                            cur+=k.second;
                        ans=max(ans,cur);
                    }
                }
            }
        }
        return ans;
    }
};
