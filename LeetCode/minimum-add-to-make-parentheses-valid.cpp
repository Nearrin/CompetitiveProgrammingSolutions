class Solution {
public:
    int minAddToMakeValid(string a) {
        int s=0,d=0;
        for(auto c:a)s+=map<char,int>{{'(',1},{')',-1}}[c],d+=s<0,s=max(s,0);
        return s+d;
    }
};
