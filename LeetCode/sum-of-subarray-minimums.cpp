class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        vector<pair<int,int>>b;
        for(int i=0;i<a.size();++i)
            b.emplace_back(a[i],i);
        auto l=a,r=a;
        stack<pair<int,int>>s;
        for(int i=0;i<b.size();++i){
            while(s.size()&&s.top()>b[i])
                s.pop();
            if(!s.size())l[i]=0;
            else l[i]=s.top().second+1;
            s.push(b[i]);
        }
        s=stack<pair<int,int>>();
        for(int i=b.size()-1;i>=0;--i){
            while(s.size()&&s.top()>b[i])
                s.pop();
            if(!s.size())r[i]=b.size()-1;
            else r[i]=s.top().second-1;
            s.push(b[i]);
        }
        long long ans=0;
        for(int i=0;i<a.size();++i){
            //cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
            ans+=(long long)(r[i]-i+1)*(i-l[i]+1)*a[i];
        }
        return ans%int(1e9+7);
    }
};
