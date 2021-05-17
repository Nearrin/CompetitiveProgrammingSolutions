#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= int(l); --i)
#define rang(a) begin(a), end(a)
#define gene template <class T>
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) {
    return accumulate(rang(a), (typename T::value_type)0);
}
template <> auto sum(const vector<int> &a) { return accumulate(rang(a), 0ll); }
gene auto vect(const vector<T> &v, int n) {
    assert(v.size() <= 1);
    return v.size() ? vector<T>(n, v[0]) : vector<T>(n);
}
template <class T, class... D> auto vect(const vector<T> &v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
void ou() { cout << endl; }
gene void ou(const T &a) { cout << a << endl; }
template <class A, class... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
class Solution {
public:
    int minDifficulty(vector<int>& a, int d) {
        int n=a.size();
        auto f=vect<int>({inf()/2},n+1,d+1);
        f[0][0]=0;
        lp(j,1,d){
            stack<int>p,g;
            lp(i,1,n){
                int t=f[i-1][j-1];
                while(p.size()&&a[p.top()-1]<=a[i-1])
                    p.pop(),tmin(t,g.top()),g.pop();
                f[i][j]=min(f[p.size()?p.top():0][j],t+a[i-1]);
                p.push(i),g.push(t);
            }
        }
        return f[n][d]==inf()/2?-1:f[n][d];
    }
};
