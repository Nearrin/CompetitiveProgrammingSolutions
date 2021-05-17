class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>segments;
        vector<int>points;
        for(int i=0;i<=n;++i){
            segments.emplace_back(i-ranges[i],i+ranges[i]);
        }
        for(int i=0;i<n;++i)
            points.push_back(n-i-1);
        sort(segments.begin(),segments.end());
        reverse(segments.begin(),segments.end());
        int ans=0;
        while(true){
            if(points.empty())
                break;
            int p=points.back();
            points.pop_back();
            int r=p;
            while(segments.size()&&segments.back().first<=p){
                r=max(r,segments.back().second);
                segments.pop_back();
            }
            if(r<p+1)
                return -1;
            ++ans;
            while(points.size()&&points.back()+1<=r)
                points.pop_back();
        }
        return ans;
    }
};
