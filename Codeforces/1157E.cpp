#include <iostream>
#include <set>
#include <string>
#include <utility>
template <typename T> struct Set {
    void add(const T &a) { data.insert(a); }
    std::pair<T, int> remove_one(const T &a) {
        auto i = data.find(a);
        if (i == data.end())
            return std::make_pair(a, 0);
        data.erase(i);
        return std::make_pair(a, 1);
    }
    std::pair<T, int> remove_all(const T &a) {
        return std::make_pair(a, data.erase(a));
    }
    std::pair<T, int> remove_ge(const T &a) {
        auto i = data.lower_bound(a);
        if (i == data.end())
            return std::make_pair(a, 0);
        auto r = *i;
        data.erase(i);
        return std::make_pair(r, 1);
    }
    std::pair<T, int> remove_min() {
        if (!data.size())
            return std::make_pair(T(), 0);
        auto r = *data.begin();
        data.erase(data.begin());
        return std::make_pair(r, 1);
    }
    std::pair<T, int> remove_max() {
        if (!data.size())
            return std::make_pair(T(), 0);
        auto r = *data.rbegin();
        data.erase(data.rbegin());
        return std::make_pair(r, 1);
    }
    int count(const T &a) const { return data.count(a); }
    typename std::multiset<T>::iterator begin() { return data.begin(); }
    typename std::multiset<T>::const_iterator begin() const {
        return data.begin();
    }
    typename std::multiset<T>::iterator end() { return data.end(); }
    typename std::multiset<T>::const_iterator end() const { return data.end(); }
    int size() { return data.size; }
    operator std::string() const {
        std::string s = "{";
        for (auto a : data)
            s += std::to_string(a) + ", ";
        return s.substr(0, s.size() - 2) + "}";
    }
    std::multiset<T> data;
};
template <typename T>
std::ostream &operator<<(std::ostream &s, const Set<T> &a) {
    return s << std::string(a);
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    vector<int> a;
    Set<int> b;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        b.add(t);
    }
    for (int i = 0; i < n; ++i) {
        int t = (n - a[i]) % n;
        auto r = b.remove_ge(t);
        if (r.second) {
            cout << (a[i] + r.first) % n;
        } else {
            cout << (a[i] + b.remove_min().first) % n;
        }
        if (i != n - 1)
            cout << ' ';
        else
            cout << endl;
    }
    return 0;
}
