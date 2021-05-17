class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>ans(A.size());
        for(int i=1;i<A.size();++i){
            A[i]=(A[i-1]*2+A[i])%5;
            ans[i]=A[i]==0;
        }
        ans[0]=A[0]==0;
        return ans;
    }
};
