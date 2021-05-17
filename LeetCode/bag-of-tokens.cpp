class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        for (int l = 0,h = tokens.size()-1;l<=h;) 
            if (P>=tokens[l]) {
                score++;
                P-=tokens[l++];
                continue;
            }
            else {
                if (l==h) break;//its not good option to spend token for power,because there is not any token we can buy
                if (score==0) break;//we can not buy token,and also can not sell token,so its over
                score--;
                P+=tokens[h--];
            }
        
        return score;
    }
};
