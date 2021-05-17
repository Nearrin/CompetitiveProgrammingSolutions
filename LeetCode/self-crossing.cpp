#include <bits/stdc++.h>
using namespace std;
namespace geometry_2d {
template <class T> struct vector_2d {
    vector_2d(T i = 0, T j = 0) : x(i), y(j) {}
    vector_2d(const vector<T> &v) : x(v[0]), y(v[1]) { assert(v.size() == 2); }
    int dir() const { return x ? x < 0 : (y ? y < 0 : -1); }
    operator vector<T>() const {
        vector<T> v;
        v.push_back(x);
        v.push_back(y);
        return v;
    }
    T x, y;
};
template <class T> double angle(const vector_2d<T> &a) {
    return atan2(double(a.x), double(a.y));
}
template <class T> T squared_euclidean_norm(const vector_2d<T> &a) {
    return a.x * a.x + a.y * a.y;
}
template <class T> T euclidean_norm(const vector_2d<T> &a) {
    return sqrt(squared_euclidean_norm(a));
}
template <class T>
T cross_product(const vector_2d<T> &a, const vector_2d<T> &b) {
    return a.x * b.y - b.x * a.y;
}
template <class T> T dot_product(const vector_2d<T> &a, const vector_2d<T> &b) {
    return a.x * b.x + b.y * a.y;
}
template <class T>
auto operator+(const vector_2d<T> &a, const vector_2d<T> &b) {
    return vector_2d<T>(a.x + b.x, a.y + b.y);
}
template <class T>
auto operator-(const vector_2d<T> &a, const vector_2d<T> &b) {
    return vector_2d<T>(a.x - b.x, a.y - b.y);
}
template <class T> auto operator*(const vector_2d<T> &a, const T &b) {
    return vector_2d<T>(a.x * b, a.y * b);
}
template <class T> auto operator/(const vector_2d<T> &a, const T &b) {
    return vector_2d<T>(a.x / b, a.y / b);
}
template <class T> T operator<(const vector_2d<T> &a, const vector_2d<T> &b) {
    int t = a.dir() - b.dir();
    return t ? (t < 0) : (cross_product(a, b) < 0);
}
template <class T> auto &operator>>(istream &s, vector_2d<T> &a) {
    return s >> a.x >> a.y;
}
template <class T> auto &operator<<(ostream &s, const vector_2d<T> &a) {
    return s << '(' << a.x << ", " << a.y << ')';
}
template <class T> struct line_2d {
    line_2d(const vector_2d<T> &p_, const vector_2d<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    vector_2d<T> p, q;
    double a;
};
template <class T> auto intersection(const line_2d<T> &a, const line_2d<T> &b) {
    double a1 = cross_product(b.p - a.q, b.q - b.p),
           a2 = cross_product(a.p - b.q, b.q - b.p);
    if (abs(a1 + a2) < 1e-8)
        return vector<vector_2d<T>>();
    else
        return vector<vector_2d<T>>(1, (a.p * a1 + a.q * a2) / (a1 + a2));
}
template <class T> struct segment_2d {
    segment_2d(const vector_2d<T> &p_, const vector_2d<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    segment_2d(const vector<T> &p_, const vector<T> &q_)
        : p(p_), q(q_), a(angle(p - q)) {}
    operator line_2d<T>() const { return line_2d<T>(p, q); }
    vector_2d<T> p, q;
    double a;
};
template <class T>
auto contains(const segment_2d<T> &a, const vector_2d<T> &b) {
    return abs(cross_product(a.q - a.p, b - a.p)) < 1e-8 &&
           dot_product(b - a.p, b - a.q) < 1e-8;
}
template <class T>
auto intersection(const segment_2d<T> &a, const segment_2d<T> &b) {
    auto i = intersection(line_2d<T>(a), line_2d<T>(b));
    vector<vector_2d<T>> r, t;
    if (i.size())
        r = i;
    else {
        r.push_back(a.p);
        r.push_back(a.q);
        r.push_back(b.p);
        r.push_back(b.q);
    }
    for (auto p : r)
        if (contains(a, p) && contains(b, p))
            t.push_back(p);
    return t;
}
} // namespace geometry_2d
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        using namespace geometry_2d;
        vector<segment_2d<double>>a;
        double px=0,py=0;
        for(int i=0;i<x.size();++i){
            double qx,qy;
            if(i%4==0)qx=px,qy=py+x[i];
            else if(i%4==1)qx=px-x[i],qy=py;
            else if(i%4==2)qx=px,qy=py-x[i];
            else qx=px+x[i],qy=py;
            segment_2d<double> tmp(vector<double>{px,py},vector<double>{qx,qy});
            for(int j=1;j<8&&i-1-j>=0;++j)if(intersection(a[i-j-1],tmp).size()){
                //cout<<i-j-1<<" "<<i<<endl;
                return true;
            }
            a.push_back(tmp);
            px=qx,py=qy;
        }
        return false;
    }
};
