class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto f=[](string s){
            int t=0;
            for(auto c:s)t=t*10+c-'a';
            return t;
        };
        return f(firstWord)+f(secondWord)==f(targetWord);
    }
};
