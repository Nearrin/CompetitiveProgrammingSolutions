class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>a;
        for(auto w:words){
            string t;
            for(auto c:w)
            {
                static string code[26]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---"
                    ,".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
                t+=code[c-'a'];
            }
            a.insert(t);
        }
        return a.size();
    }
};
