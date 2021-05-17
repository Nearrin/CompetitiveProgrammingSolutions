class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        if(!a.count(tweetName)){
            a[tweetName].resize(60);
        }
        auto&b=a[tweetName];
        for(int r=0;r<60;++r){
            b[r][(time+r)/60].push_back(time);
        }
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        auto&b=a[tweetName];
        int l;
        if(freq=="minute")
            l=1;
        else if(freq=="hour")
            l=60;
        else
            l=60*24;
        int ll;
        if( (endTime-startTime+1)%(l*60) == 0)
            ll= (endTime-startTime+1)/(l*60);
        else
            ll= (endTime-startTime+1)/(l*60)+1;
        vector<int>ans(ll);
        int r=(60-startTime%60)%60;
        auto&c=b[r];
        int x=(startTime+r)/60,y=(endTime+r)/60;
        for(int i=x;i<=y;++i){
            int cur=0;
            if(i==y){
                for(auto tmp:c[i])if(tmp<=endTime)++cur;
            }else cur=c[i].size();
            ans[ (i-x)/l]+=cur;
        }
        return ans;
    }
private:
    unordered_map<string,vector<unordered_map<int,vector<int>>>>a;
    
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
