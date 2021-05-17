template <class T> struct kmp_algorithm {
    kmp_algorithm(const T &_b) : b(_b), p(b.size(), -1) {
        int j = 0;
        for (int i = 1; i < b.size(); ++i) {
            j = p[i - 1];
            for (; j != -1 && b[j + 1] != b[i]; j = p[j])
                ;
            p[i] = j + (b[j + 1] == b[i]);
        }
    }
    auto run(const T &a) {
        vector<int> r,r2;
        for (int i = 0, j = -1; i < a.size(); ++i) {
            for (; j != -1 && b[j + 1] != a[i]; j = p[j])
                ;
            j += (b[j + 1] == a[i]);
            r2.push_back(j+1);
            j + 1 == b.size() && (r.push_back(i - j), j = p[j]);
        }
        return r2;
    }
    T b;
    vector<int> p;
};
class Solution {
public:
    string longestPrefix(string s) {
        if(s.size()==1)return "";
        kmp_algorithm ka(s);

        string s2;
        for(int i=1;i<s.size();++i)s2.push_back(s[i]);
                auto tmp=ka.run(s2);
        
        return s.substr(0,tmp.back());
    }
};
