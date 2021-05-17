class Solution {
public:
    int scoreOfParentheses(string a) {
        using ll=long long;
        vector<ll>u;
        ll ans=0;
        for(auto c:a){
            if(c=='(')
                u.push_back(0);
            else{
                if(!u.back())
                    ++u.back();
                else
                    u.back()*=2;
                if(u.size()>1)
                    u[u.size()-2]+=u.back();
                else
                    ans+=u.back();
                u.pop_back();
            }
        }
        return ans;
    }
};
