class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
        string ans;
        for(char c:s){
            if(c==')'&&cnt==0)continue;
            ans.push_back(c);
            cnt+=c=='(';
            cnt-=c==')';
        }
        string ans2;
        while(ans.size()){
            if(ans.back()=='('&&cnt)
                --cnt;
            else
                ans2.push_back(ans.back());
            ans.pop_back();
        }
        reverse(begin(ans2),end(ans2));
        return ans2;
    }
};
