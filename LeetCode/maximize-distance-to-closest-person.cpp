class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        for(int i=0;i<seats.size();++i){
            if(seats[i])continue;
            int j=i;
            while(j+1<seats.size()&&!seats[j+1])++j;
            if(i==0||j+1==seats.size())ans=max(ans,j-i+1);
            else{
                ans=max(ans,(j-i+1)/2+((j-i+1)%2==1));
            }
        }
        return ans;
    }
};
