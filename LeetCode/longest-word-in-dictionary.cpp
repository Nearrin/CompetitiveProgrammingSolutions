class Solution {
public:
    string longestWord(vector<string>& words) {
        map<string,int>can;
        string ans;
        sort(begin(words),end(words),[](string u,string v){return u.size()<v.size();});
        for(auto u:words){
            if(u.size()==1){
                can[u]=1;
            }else if(can[u.substr(0,u.size()-1)]){
                can[u]=1;
            }
            if(can[u]){
                if(ans.size()<u.size()||ans>u)ans=u;
            }
        }
        return ans;
    }
};
