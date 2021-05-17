class Solution {
public:
    bool isPossible(vector<int>& target) {
        multiset<long long>a;
        long long b=0;
        for(auto v:target){
            a.insert(v);
            b+=v;
        }
        while(true){
            long long x=*a.rbegin();
            //cout<<x<<endl;
            a.erase(a.find(x));
            if(x==1)
                return true;
            if(x-(b-x)<1)
                return false;
            long long d=b-x;
            x-=d;
            b-=d;
            a.insert(x);
        }
        return true;
    }
};
