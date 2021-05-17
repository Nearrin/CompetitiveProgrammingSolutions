class Solution {
public:
    int binaryGap(int n) {
        auto a=bitset<64>(n);
        int ans=0;
        vector<int>tmp;
        for(int i=0;i<a.size();++i)
            if(a[i])tmp.push_back(i);
        for(int i=1;i<tmp.size();++i)ans=max(ans,tmp[i]-tmp[i-1]);
        return ans;
    }
};
