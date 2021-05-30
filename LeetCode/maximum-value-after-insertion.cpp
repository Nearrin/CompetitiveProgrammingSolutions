class Solution {
public:
    string maxValue(string n, int x) {
        auto c=x+'0';
        string t;
        if(n.front()!='-'){
            for(auto i:n){
                if(i>=c||c==0)t.push_back(i);
                else{
                    t.push_back(c);
                    t.push_back(i);
                    c=0;
                }
            }
            if(c)t.push_back(c);
        }else{
            for(auto i:n){
                if(i<=c||c==0)t.push_back(i);
                else{
                    t.push_back(c);
                    t.push_back(i);
                    c=0;
                }
            }
            if(c)t.push_back(c);
        }
        return t;
    }
};
