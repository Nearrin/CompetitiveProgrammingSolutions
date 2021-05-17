class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char>t;
        for(auto c:s)if(c>='a'&&c<='z'||c>='A'&&c<='Z')t.push_back(c);
        for(auto&c:s)if(c>='a'&&c<='z'||c>='A'&&c<='Z')c=t.back(),t.pop_back();
        return s;
    }
};
