class Solution {
public:
    int longestSubarray(vector<int>& a, int k) {
        int ans=0;
        multiset<int>cur;
        int j=0;
        for(int i=0;i<a.size();++i){
            while(cur.size()&&(abs(*cur.begin()-a[i])>k||abs(*cur.rbegin()-a[i])>k)){
                cur.erase(a[j++]);
            }
            cur.insert(a[i]);
            ans=max(ans,(int)cur.size());
        }
        return ans;
    }
};
