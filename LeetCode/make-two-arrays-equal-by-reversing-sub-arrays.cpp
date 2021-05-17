class Solution {
public:
    bool canBeEqual(vector<int>& a, vector<int>& b) {
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        for(int i=0;i<a.size();++i)if(a[i]!=b[i])return 0;
        return 1;
    }
};
