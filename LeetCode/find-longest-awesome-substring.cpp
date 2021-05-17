class Solution {
public:
    int longestAwesome(string s) {
        int curs=0;
        unordered_map<int,int>pos;
        pos[0]=-1;
        int ans=0;
        for(int i=0;i<s.size();++i){
            curs^=(1<<((s[i]-'0')));
            if(pos.count(curs)){
                ans=max(ans,i-pos[curs]+1);
            }
            for(int j=0;j<10;++j){
                if(pos.count(curs^(1<<j))){
                ans=max(ans,i-pos[curs^(1<<j)]+1);
            }
            }
            if(!pos.count(curs))pos[curs]=i;
        }
        return ans-1;
    }
};
