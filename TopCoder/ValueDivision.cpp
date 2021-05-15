#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
struct ValueDivision {
    vi getArray(vi a) {
        while (true) {
            int fail = 1;
            unordered_map<int, pii> c;
            for (auto v : a)
                ++c[v].first;
            for (auto &v : a) {
                auto &t = c[v];
                if (v > 1 && t.second < t.first / 2) {
                    --v;
                    ++t.second;
                    fail = 0;
                }
            }
            if (fail)
                break;
        }
        return a;
    }
};