class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>idx;
        for(int i=0;i<arr2.size();++i)idx[arr2[i]]=i;
        auto get_idx=[&](int x){if(idx.count(x))return idx[x];return (int)arr2.size();};
        sort(arr1.begin(),arr1.end(),[&](int x,int y){return make_pair(get_idx(x),x)<make_pair(get_idx(y),y);});
        return arr1;
    }
};
