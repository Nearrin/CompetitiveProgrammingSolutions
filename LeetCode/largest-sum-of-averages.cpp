#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define rp(i, r, l) for (int i = int(r); i >= int(l); --i)
#define rang(a) begin(a), end(a)
#define gene template <class T>
template <class T = int> T inf() { return numeric_limits<T>::max() / 2; }
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef string str;
class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int k) {
        int n=a.size();
        auto f=vect<double>({-inf<double>()},n+1,k+1);
        lp(i,0,k)f[0][i]=0;
        lp(i,1,n){
            lp(j,1,k){
                double s=0,c=0;
                rp(l,i-1,0){
                    ++c,s+=a[l];
                    tmax(f[i][j],f[l][j-1]+s/c);
                }
            }
        }
        return f[n][k];
    }
};
