class Solution {
public:
    string sortString(string s) {
        string ans;
        vector<int>cnt(26);
        for(auto c:s)cnt[c-'a']++;
        while(true){
           
                int i=0;
                while(i<cnt.size()&&cnt[i]==0)++i;
                if(i==cnt.size())return ans;
                ans.push_back('a'+i);
                --cnt[i];
                for(int j=i+1;j<cnt.size();++j)if(cnt[j]){
                    --cnt[j];
                    ans.push_back('a'+j);
                }
            
           
                  i=25;
                while(i>=0&&cnt[i]==0)--i;
                if(i==-1)return ans;
                ans.push_back('a'+i);
                --cnt[i];
                for(int j=i-1;j>=0;--j)if(cnt[j]){
                    --cnt[j];
                    ans.push_back('a'+j);
                }
                
            
        }
    }
};
