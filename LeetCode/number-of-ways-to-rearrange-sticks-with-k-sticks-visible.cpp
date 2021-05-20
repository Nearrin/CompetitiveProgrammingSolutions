#include <bits/stdc++.h>
using namespace std;
namespace modular_arithmetic {
#ifdef LOCAL
template <class T> T multiply(T x, T y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(long long a, long long b, const long long &c) {
    ll r = 0;
    for (; b; b & 1 ? r = (r + a) % c : 0, b >>= 1, a = (a + a) % c)
        ;
    return r;
}
#else
template <class T> T multiply(const T &x, const T &y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(const long long &x, const long long &y,
                              const long long &z) {
    return (x * y - (long long)(((long double)x * y + 0.5) / z) * z + z) % z;
}
#endif
template <class T = int, T M = 998244353> struct integer {
    integer() : v(0) {}
    integer(T t) : v(t) { wrap_around(); }
    integer(int64_t t) {
        if (t < 0)
            v = (t % M + M) % M;
        else if (t >= M)
            v = t % M;
    }
    void wrap_around() {
        if (v < 0)
            v = (v % M + M) % M;
        else if (v >= M)
            v %= M;
    }
    integer<T, M> operator-() const {
        integer<T, M> a;
        a.v = (v ? M - v : 0);
        return a;
    }
    integer<T, M> &operator+=(integer<T, M> a) { return *this = *this + a; }
    integer<T, M> &operator-=(integer<T, M> a) { return *this = *this - a; }
    integer<T, M> &operator*=(integer<T, M> a) { return *this = *this * a; }
    integer<T, M> &operator/=(integer<T, M> a) { return *this = *this / a; }
    integer<T, M> &operator<<=(T a) { return *this = *this << a; };
    integer<T, M> &operator>>=(T a) { return *this = *this >> a; };
    friend integer<T, M> operator/(integer<T, M> a, integer<T, M> b) {
        return a * inverse(b);
    }
    friend integer<T, M> operator+(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v + b.v;
        if (c.v >= M)
            c.v -= M;
        return c;
    }
    friend integer<T, M> operator-(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = a.v - b.v;
        if (c.v < 0)
            c.v += M;
        return c;
    }
    friend integer<T, M> operator*(integer<T, M> a, integer<T, M> b) {
        integer<T, M> c;
        c.v = multiply(a.v, b.v, M);
        return c;
    }
    friend integer<T, M> operator^(integer<T, M> a, T b) { return pow(a, b); }
    friend bool operator==(integer<T, M> a, integer<T, M> b) {
        return a.v == b.v;
    }
    friend bool operator!=(integer<T, M> a, integer<T, M> b) {
        return a.v != b.v;
    }
    friend bool operator<(integer<T, M> a, integer<T, M> b) {
        return a.v < b.v;
    };
    friend bool operator<=(integer<T, M> a, integer<T, M> b) {
        return a.v <= b.v;
    };
    friend bool operator>(integer<T, M> a, integer<T, M> b) {
        return a.v > b.v;
    };
    friend bool operator>=(integer<T, M> a, integer<T, M> b) {
        return a.v >= b.v;
    };
    friend istream &operator>>(istream &s, integer<T, M> &a) {
        s >> a.v;
        a.wrap_around();
        return s;
    }
    friend ostream &operator<<(ostream &s, integer<T, M> a) { return s << a.v; }
    friend integer<T, M> operator<<(integer<T, M> a, T b) {
        return a * pow(integer<T, M>(2), b);
    }
    friend integer<T, M> operator>>(integer<T, M> a, T b) {
        return a / pow(integer<T, M>(2), b);
    }
    static integer<T, M> pow(integer<T, M> a, T b) {
        integer<T, M> r(1);
        if (b < 0)
            a = 1 / a, b = -b;
        for (; b; b >>= 1, a = a * a)
            if (b & 1)
                r = r * a;
        return r;
    }
    // Not tested.
    static integer<T, M> sqrt(integer<T, M> a) {
        vector<integer<T, M>> r;
        if (!a.v)
            r.push_back(decltype(r)(0));
        else if (pow(a, M - 1 >> 1).v == 1) {
            int s = M - 1, t = 0;
            integer<T, M> b = 1;
            for (; pow(b, M - 1 >> 1).v != M - 1; b = integer<T, M>::random())
                ;
            for (; s % 2 == 0; ++t, s /= 2)
                ;
            integer<T, M> x = pow(a, (s + 1) / 2), e = pow(a, s);
            for (int i = 1; i < t; ++i, e = x * x / a)
                if (pow(e, 1 << t - i - 1).v != 1)
                    x = x * pow(b, (1 << i - 1) * s);
            r.push_back(x);
            r.push_back(-x);
        }
        return r;
    }
    static T extended_euclidean_algorithm(T a, T b, T &x, T &y) {
        if (!b) {
            x = 1, y = 0;
            return a;
        } else {
            T d = extended_euclidean_algorithm(b, a % b, y, x);
            y -= a / b * x;
            return d;
        }
    }
    static integer<T, M> inverse(integer<T, M> a) {
        assert(a.v);
        if (a.v < T(integer<T, M>::inverse_cache.size()))
            return integer<T, M>::inverse_cache[a.v];
        T t;
        extended_euclidean_algorithm(a.v, M, a.v, t);
        if (a.v < 0)
            a.v += M;
        return a;
    }
    static integer<T, M> inverse_cached(const integer<T, M> &a) {
        assert(a.v);
        auto &t = inverse_cache;
        while (int(t.size()) <= a.v) {
            t.push_back(integer<T, M>(-M / T(t.size())) * t[M % t.size()]);
        }
        return t[a.v];
    }
    static integer<T, M> factorial(const T &a) {
        assert(a >= 0);
        auto &t = factorial_cache;
        while (a >= int(t.size()))
            t.push_back(t.back() * T(t.size()));
        return t[a];
    }
    static integer<T, M> factorial_inverse(const T &a) {
        assert(a >= 0);
        auto &t = factorial_inverse_cache;
        while (a >= int(t.size()))
            t.push_back(t.back() * inverse_cached(T(t.size())));
        return t[a];
    }
    static integer<T, M> binary_coefficient(T n, T k) {
        assert(n >= 0 && k >= 0);
        if (n < k)
            return integer<T, M>();
        return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
    }
    static integer<T, M> lagrange_interpolation(const vector<integer<T, M>> &y,
                                                integer<T, M> x) {
        vector<integer<T, M>> f(1, 1), g(y.size(), x), h(y.size(), x);
        for (int i = 1; i < int(y.size()); ++i) {
            f.push_back(f.back() * inverse_cached(i));
            g[i] = h[i] -= i, g[i] *= g[i - 1];
        }
        for (int i = int(y.size()) - 2; i >= 0; --i)
            h[i] *= h[i + 1];
        integer<T, M> r = 0;
        for (int i = 0; i < int(y.size()); ++i) {
            integer<T, M> t = f[i] * f[y.size() - 1 - i];
            if (i)
                t *= g[i - 1];
            if (i + 1 != int(y.size()))
                t *= h[i + 1];
            if (int(y.size() - i - 1) % 2)
                t = -t;
            r += t * y[i];
        }
        return r;
    }
    static integer<T, M> random() {
        return integer<T, M>(uniform_int_distribution<T>(0, M - 1)(generator));
    }
    T v;
    static mt19937_64 generator;
    static vector<integer<T, M>> inverse_cache, factorial_cache,
        factorial_inverse_cache;
};
template <class T, T M>
mt19937_64 integer<T, M>::generator(
    chrono::steady_clock::now().time_since_epoch().count());
template <class T, T M>
vector<integer<T, M>> integer<T, M>::inverse_cache(2, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::factorial_cache(1, T(1));
template <class T, T M>
vector<integer<T, M>> integer<T, M>::factorial_inverse_cache(1, T(1));
const int candidate = 1073741789;
} // namespace modular_arithmetic
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        using inte=modular_arithmetic::integer<int,int(1e9+7)>;
        static inte c[1010][1010];
        for(int i=0;i<=n;++i)
            for(int j=0;j<=i;++j){
                if(j==0||j==i)c[i][j]=1;
                else c[i][j]=c[i-1][j]+c[i-1][j-1];
            }
        static inte f[1010][1010],s[1010][1010];
        f[0][0]=1;
        s[0][0]=1;
        for(int i=1;i<=n;++i){
            s[i][0]=1;
            for(int j=1;j<=n;++j){
                    f[i][j]=0;
                    //for(int t=1;t<=i;++t)
                    //    f[i][j]+=f[t-1][j-1]*inte::factorial_inverse(t-1);
                    f[i][j]=s[i-1][j-1];
                    f[i][j]*=inte::factorial(i-1);
                    s[i][j]=s[i-1][j]+f[i][j]*inte::factorial_inverse(i);
                }
            }
        return f[n][k].v;
    }
};
