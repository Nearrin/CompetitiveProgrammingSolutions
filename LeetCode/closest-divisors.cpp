class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int>ans;
        int diff=~0u>>1;
        for(int p=num+1;p<=num+2;++p){
            for(int u=1;u*u<=p;++u){
                if(p%u==0){
                    int v=p/u;
                    if(v-u<diff){
                        diff=v-u;
                        ans.clear();
                        ans.push_back(u);
                        ans.push_back(v);
                    }
                }
            }
        }
        return ans;
    }
};
