class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        buffer[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto tmp=buffer[id];
        auto&tmp2=cnt[tmp.first][stationName];
        ++tmp2.first;
        tmp2.second+=t-tmp.second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto&tmp2=cnt[startStation][endStation];
        return tmp2.second/tmp2.first;
    }
    unordered_map<int,pair<string,int>>buffer;
    unordered_map<string,map<string,pair<double,double>>>cnt;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
