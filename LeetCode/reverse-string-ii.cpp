class Solution {
public:
    string reverseStr(string s, int k) {
        auto f=[&](int l,int r){
            while(l<r){
                swap(s[l],s[r]);
                ++l,--r;
            }
        };
        for(int i=0;i<s.size();i+=2*k){
            int l=i,r=min(int(s.size()-1),i+k-1);
            f(l,r);
        }
        return s;
    }
};
