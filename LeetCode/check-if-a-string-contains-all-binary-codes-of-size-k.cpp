class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>a;
        for(int i=0;i<int(s.size()-k+1);++i){
            string t;
            for(int j=0;j<k;++j)
                t.push_back(s[i+j]);
            a.insert(t);
        }
        return a.size()==(1<<k);
    }
};
