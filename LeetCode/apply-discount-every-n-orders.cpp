class Cashier {
public:
    Cashier(int n_, int discount_, vector<int>& products_, vector<int>& prices_) {
        n=n_;
        discount=discount_;
        for(int i=0;i<products_.size();++i)
            price[products_[i]]=prices_[i];
        cnt=0;
    }
    double getBill(vector<int> product, vector<int> amount) {
        double ans=0;
        for(int i=0;i<product.size();++i){
            ans+=price[product[i]]*amount[i];
        }
        ++cnt;
        if(cnt%n==0){
            ans-= (discount * ans) / 100;
        }
        return ans;
    }
    int n;
    int discount;
    unordered_map<int,int>price;
    int cnt;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
