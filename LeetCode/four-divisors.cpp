struct linear_sieve {
    linear_sieve(int n) : next(n + 1) {
        vector<bool> is_prime(n + 1, 1);
        is_prime[1] = false;
        for (int i = 2; i <= n; ++i) {
            is_prime[i] && (p.push_back(i), next[i] = i);
            for (int j = 0; j < int(p.size()) && p[j] * i <= n; ++j) {
                is_prime[p[j] * i] = 0, next[p[j] * i] = p[j];
                if (i % p[j] == 0)
                    break;
            }
        }
    }
    auto run(int n) {
        assert(n >= 1);
        vector<pair<int, int>> a;
        while (n != 1) {
            int t = next[n];
            n /= t;
            if (a.empty() || a.back().first != t)
                a.emplace_back(t, 1);
            else
                ++a.back().second;
        }
        return a;
    }
    vector<int> next, p;
};
template <class T> auto divisor(vector<pair<T, int>> a) {
    vector<T> r;
    function<void(int, T)> dfs = [&dfs, &a, &r](int i, T now) {
        if (i == int(a.size())) {
            r.push_back(now);
            return;
        }
        for (int j = 0; j <= a[i].second; ++j) {
            dfs(i + 1, now);
            if (j < a[i].second)
                now *= a[i].first;
        }
    };
    dfs(0, 1);
    return r;
}
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        linear_sieve ls(100010);
        int ans=0;
        for(auto a:nums){
            auto tmp=divisor(ls.run(a));
            if(tmp.size()==4){
                for(auto uu:tmp)ans+=uu;
            }
        }
        return ans;
    }
};
