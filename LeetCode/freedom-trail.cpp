class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>f(key.size()+1,vector<int>(ring.size(),~0u>>1));
        f[0][0]=0;
        for(int i=0;i<key.size();++i)
            for(int j=0;j<ring.size();++j){
                if(f[i][j]==~0u>>1)
                    continue;
                for(int k=0;k<ring.size();++k)
                    if(ring[k]==key[i])
                        f[i+1][k]=min(f[i+1][k],f[i][j]+1+min(abs(k-j),(int)ring.size()-abs(k-j)));
            }
        return *min_element(begin(f.back()),end(f.back()));
    }
};
