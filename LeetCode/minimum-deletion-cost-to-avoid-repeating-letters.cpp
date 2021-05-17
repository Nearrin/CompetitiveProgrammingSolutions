class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans=0;
        for(int i=0;i<s.size();++i){
            int j=i;
            while(j+1<s.size()&&s[j+1]==s[j])++j;
            int t=cost[i];
            int t2=0;
            for(int k=i;k<=j;++k)t=max(t,cost[k]),t2+=cost[k];
            ans+=t2-t;
            i=j;
        }
        return ans;
    }
};
