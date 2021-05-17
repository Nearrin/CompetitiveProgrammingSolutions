class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>a=arr;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        vector<int>ans;
        for(int i=0;i<arr.size();++i){
            ans.push_back(lower_bound(a.begin(),a.end(),arr[i])-a.begin()+1);
        }
        return ans;
    }
};
