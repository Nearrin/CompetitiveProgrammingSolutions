class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        static int c[31][31];
        for(int i=0;i<=30;++i){
            for(int j=0;j<=i;++j){
                if(j==0||i==j)c[i][j]=1;
                else c[i][j]=c[i-1][j]+c[i-1][j-1];
            }
        }
        int ch=destination[1],cv=destination[0];
        string ans;
        while(ch+cv){
            if(ch==0){
                ans+="V";
                --cv;
            }else if(cv==0){
                ans+="H";
                --ch;
            }else{
                //cout<<ch<<cv<<endl;
                int cnt=c[ch+cv-1][ch-1];
                //cout<<cnt<<" "<<k<<endl;
                if(cnt>=k){
                    --ch;
                    ans+="H";
                }else{
                    k-=cnt;
                    --cv;
                    ans+="V";
                }
            }
        }
        return ans;
    }
};
