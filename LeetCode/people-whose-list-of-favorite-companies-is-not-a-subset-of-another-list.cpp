class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& a) {
        unordered_map<string,int>index;
        vector<unordered_set<int>>b;
        for(auto i:a){
            b.push_back(unordered_set<int>());
            for(auto j:i){
                if(!index.count(j)){
                    int t=index.size();
                    index[j]=t;
                }
                b.back().insert(index[j]);
            }
        }
        vector<int>ans;
        for(int i=0;i<b.size();++i){
            int ok=1;
            for(int j=0;j<b.size();++j){
                if(i==j)continue;
                if(b[j].size()<=b[i].size())
                    continue;
                int fail=0;
                for(auto t:b[i])if(!b[j].count(t)){
                    fail=1;
                    break;
                }
                if(!fail){
                    ok=0;
                    break;
                }
            }
            if(ok)ans.push_back(i);
        }
        return ans;
    }
};
