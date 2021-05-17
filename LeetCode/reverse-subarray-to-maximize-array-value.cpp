int work(vector<int>& a){
    int d=0;
    int n=a.size();
    int t=~0u>>1;
    for(int i=1;i<=n-2;++i){
        t=min(t,max(a[i],a[i-1]));
        if(min(a[i],a[i+1])>=t)
            d=max(d,(min(a[i],a[i+1])-t)*2);
    }
    return d;
}
void work2(vector<int>& a){
    int ans=0,a2,a3;
    for(int i=0;i<a.size();++i){
        for(int j=i;j<a.size();++j){
            reverse(a.begin()+i,a.begin()+j+1);
            int base=0;
            for(int k=0;k+1<a.size();++k)
                base+=abs(a[k]-a[k+1]);
            if(base>ans){
                ans=base;
                a2=i;
                a3=j;
            }
            reverse(a.begin()+i,a.begin()+j+1);
        }
    }
    cout<<ans<<" "<<a2<<" "<<a3<<endl;
}
class Solution {
public:
    int maxValueAfterReverse(vector<int>& a) {
        //work2(a);
        int base=0;
        for(int i=0;i+1<a.size();++i)
            base+=abs(a[i]-a[i+1]);
        if(a.size()<=2){
            return base;
        }
        int n=a.size();
        int delta=0;
        for(int j=0;j<=n-2;++j){
            delta=max(delta,-abs(a[j+1]-a[j])+abs(a[j+1]-a[0]));
        }
        for(int j=1;j<=n-1;++j){
            delta=max(delta,-abs(a[j]-a[j-1])+abs(a[j-1]-a[n-1]));
        }
        delta=max(delta,-abs(a[0]-a[1])+abs(a[0]-a[n-1]));
        delta=max(delta,-abs(a[n-1]-a[n-2])+abs(a[n-1]-a[0]));
        delta=max(delta,work(a));
        reverse(a.begin(),a.end());
        delta=max(delta,work(a));
        return base+delta;
    }
};
