class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>t;
        for(auto i:paths){
            t.insert(i[0]);
        }
        for(auto i:paths){
            if(!t.count(i[1]))
                return i[1];
        }
        return string();
    }
};
