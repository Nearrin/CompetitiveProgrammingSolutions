class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1;
        b=nums2;
        for(auto v:b)++bcnt[v];
    }
    
    void add(int index, int val) {
        --bcnt[b[index]];
        b[index]+=val;
        ++bcnt[b[index]];
    }
    
    int count(int tot) {
        int ans=0;
        for(auto v:a){
            int tv=tot-v;
            ans+=bcnt[tv];
        }
        return ans;
    }
    vector<int>a,b;
    unordered_map<int,int>bcnt;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
