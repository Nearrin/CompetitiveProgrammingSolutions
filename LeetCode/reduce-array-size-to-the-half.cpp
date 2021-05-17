class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>cnt;
        for(auto v:arr)++cnt[v];
        vector<int>a;
        for(auto v:cnt)a.push_back(v.second);
        sort(begin(a),end(a));
        reverse(begin(a),end(a));
        int cur=0;
        for(int i=0;i<a.size();++i){
            cur+=a[i];if(cur*2>=arr.size())
                return i+1;
        }
        return -1;
    }
};
