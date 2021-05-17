class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int cur=0;
        auto f=[](char c){
          return c=='a'||c=='e'||   c=='i'||c=='o'|| c=='u';
        };
        for(int i=0;i<s.size();++i){
            cur+=f(s[i]);
            if(i>=k)
                cur-=f(s[i-k]);
            ans=max(ans,cur);
        }
        return ans;
    }
};
