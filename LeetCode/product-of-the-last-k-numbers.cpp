class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num!=1){
            p.push_back(-1);
        }else{
            if(a.empty()||a.back()!=1)
                p.push_back(a.size());
            else
                p.push_back(p.back());
        }
        a.push_back(num);
    }
    
    int getProduct(int k) {
        int r=a.size()-1,l=r-k+1;
        int ans=1;
        //cout<<k<<endl;
        for(int i=r;i>=l;){
            //cout<<i<<" "<<a[i]<<endl;
            ans*=a[i];
            --i;
            if(i<l)
                break;
            if(p[i]!=-1)
                i=p[i];
        }
        return ans;
    }
    vector<int>p;
    vector<int>a;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
