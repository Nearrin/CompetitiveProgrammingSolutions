class Solution {
public:
    bool check(deque<char>&q){
        while(q.size()>1&&q.front()==q.back())q.pop_front(),q.pop_back();
        return q.size()<=1;
    }
    bool validPalindrome(string s) {
        deque<char>q;
        for(auto c:s)q.push_back(c);
        while(q.size()>1&&q.front()==q.back())q.pop_front(),q.pop_back();
        if(q.size()<=1)return true;
        auto p=q;
        q.pop_back();
        p.pop_front();
        return check(p)||check(q);
    }
};
