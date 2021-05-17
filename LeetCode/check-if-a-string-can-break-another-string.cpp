class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(begin(s1),end(s1));
        sort(begin(s2),end(s2));
        int a=0,b=0;
        for(int i=0;i<s1.size();++i){
            if(s1[i]<=s2[i])++a;
            if(s2[i]<=s1[i])++b;
        }
        return a==s1.size()||b==s1.size();
    }
};
