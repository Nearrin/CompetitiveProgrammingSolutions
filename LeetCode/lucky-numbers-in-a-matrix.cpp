class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        vector<int>a;
        vector<int>mr;
        for(int i=0;i<m.size();++i){
            int tmp=~0u>>1;
            for(int j=0;j<m[i].size();++j){
                tmp=min(tmp,m[i][j]);
            }
            mr.push_back(tmp);
        }
        vector<int>mc;
          for(int j=0;j<m[0].size();++j){
               int tmp=-(~0u>>1);
    for(int i=0;i<m.size();++i){
           
          
                tmp=max(tmp,m[i][j]);
            }
            mc.push_back(tmp);
        }
           for(int i=0;i<m.size();++i){
            
            for(int j=0;j<m[i].size();++j){
               if(m[i][j]==mr[i]&&m[i][j]==mc[j])a.push_back(m[i][j]);
            }
          
        }
        return a;
    }
};
