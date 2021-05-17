class CustomStack {
public:
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(a.size()<n)a.push_back(x);
    }
    
    int pop() {
        if(!a.size())return -1;
        int tmp=a.back();
        a.pop_back();
        return tmp;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k&&i<a.size();++i)a[i]+=val;
    }
    int n;
    vector<int>a;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
