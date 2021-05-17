class Solution {
public:
    void duplicateZeros(vector<int>& a) {
        vector<int>b;
        for(auto v:a){
            b.push_back(v);
            if(!v)b.push_back(v);
        }
        while(b.size()!=a.size())b.pop_back();
        a=b;
    }
};
