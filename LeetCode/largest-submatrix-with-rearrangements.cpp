class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans=0;
        vector<int>l(matrix[0].size()),t=l;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                if(matrix[i][j]==0){
                    l[j]=0;
                }else
                    ++l[j];
            }
            copy(begin(l),end(l),begin(t));
            sort(begin(t),end(t));
            reverse(begin(t),end(t));
            int cur=t[0];
            for(int j=0;j<t.size();++j){
                cur=min(cur,t[j]);
                ans=max(ans,cur*(j+1));
            }
        }
        return ans;
    }
};
