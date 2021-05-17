bool cmp(const vector<int>&a,const vector<int>&b){
    if (a[1]!=b[1])return a[1]>b[1];
    return a[0]>b[0];
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>ans;
        for(auto&i:restaurants){
            int f=0;
            if(veganFriendly&&!i[2])f=1;
            if(i[3]>maxPrice)f=1;
            if(i[4]>maxDistance)f=1;
            if(!f)ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int>ans2;
        for(auto&i:ans)ans2.push_back(i[0]);
        return ans2;
    }
};
