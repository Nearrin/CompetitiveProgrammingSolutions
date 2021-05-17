class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<int>>f(target+1,vector<int>(10,-1));
        f[0]=vector<int>(10,0);
        for(int i=1;i<=9;++i)
            for(int j=cost[i-1];j<=target;++j){
                auto tmp=f[j-cost[i-1]];
                if(tmp[0]==-1)continue;
                ++tmp[0];++tmp[10-i];
                f[j]=max(f[j],tmp);
                //cout<<i<<" "<<j<<" "<<f[j][0]<<endl;
            }
        if(f[target][0]==-1)
            return "0";
        string ans;
        for(int i=9;i>=1;--i)
            for(int j=1;j<=f[target][10-i];++j)
                ans.push_back('0'+i);
        return ans;
    }
};
