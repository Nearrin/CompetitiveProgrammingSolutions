class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         map<int,vector<int>>a;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;++i)for(int j=0;j<m;++j){
            a[i-j].push_back(mat[i][j]);
        }
        for(auto&i:a){
            sort(i.second.begin(),i.second.end());
            reverse(i.second.begin(),i.second.end());
        }
        for(int i=0;i<n;++i)for(int j=0;j<m;++j){
            mat[i][j]=a[i-j].back();
            a[i-j].pop_back();
        }
        return mat;
    }
};
