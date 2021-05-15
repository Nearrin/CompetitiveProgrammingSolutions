#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define CLR(x, n) memset(x, n, sizeof(x))
#define HashSz 80000
#define maxN 15
using namespace std;
typedef unsigned long long int64;

void setIO(string name) {
	string in_f = name + ".in";
	string out_f = name + ".out";
	freopen(in_f.c_str(), "r", stdin);
	freopen(out_f.c_str(), "w", stdout);
}

struct HashTable {
	
	int64 ans[HashSz];
	int stt[HashSz], num;
	int val[HashSz];
	int pos[HashSz];
	
	void init() {
		CLR(val, -1);
		CLR(pos, -1);
		num = 0;
	}
	
	void add(int st, int64 d) {
		int t = st % HashSz;
		while (val[t] != -1 && val[t] != st) {
			++t;
			if (t >= HashSz) t = 0;
		}
		if (val[t] == -1) {
			val[t] = st;
			pos[t] = num;
			stt[num] = st;
			ans[num] = d;
			++num;
		}
		else ans[pos[t]] += d;
	}
} ht1, ht2;

int n, m;
bool map[maxN][maxN];
HashTable *cur = &ht1;
HashTable *pre = &ht2;
int enx, eny;

void init() {
	scanf("%d%d\n", &n, &m);
	char ch;
	REP1(i, n) {
		REP1(j, m) {
			scanf("%c", &ch);//cout << ch;
			if (ch == '*') map[i][j] = 0;
			else map[i][j] = 1;
		}
		scanf("\n");
	}
	enx = eny = -1;
	for (int i = n; i >= 0; --i) {
		if (enx != -1) break;
		if (!i) {
			puts("0");
			exit(0);
		}
		for (int j = m; j; --j) {
			if (map[i][j]) {
				enx = i;
				eny = j;
				break;
			}
		}
	}//cout << enx << ' ' << eny << endl;
}

int get(int t) {//cout << t << ' ' << (3 << ((t - 1) << 1)) << endl; 
	return 3 << ((t - 1) << 1);
}

int status(int st, int p) {
	int ret = st & get(p);
	ret >>= (p - 1) << 1;
	return ret;
}

int set(int st, int p, int v) {
	int ret = st;
	ret &= ((1 << 30) - 1) ^ get(p);//cout << st << ' ' << p << ' ' << v << ' ' << ret << ' ';
	ret |= v << (p - 1 << 1);//cout << ret << endl;
	return ret;
}

void solve() {
	cur->init();
	cur->add(0, 1);
	REP1(i, n) {
		REP1(j, m) {
			swap(cur, pre);
			cur->init();
			REP(st, pre->num) {
				int s, s_;
				int64 d;
				s = pre->stt[st];
				d = pre->ans[st];
				int p, q;
				p = status(s, j);
				q = status(s, j + 1);//printf("%d %d %d %d %d\n", s, i, j, p, q);
				if (!map[i][j]) {
					if (!p && !q) cur->add(s, d);
					continue;
				}
				if (!p && !q) {
					if (i != n && map[i + 1][j] && j != m && map[i][j + 1]) {
						s_ = set(s, j, 1);
						s_ = set(s_, j + 1, 2);//cout << s << ' ' << j << ' ' << s_ << endl << endl;
						cur->add(s_, d);
					}
				//	else cur->add(s, d);
				}
				else if (!p ||!q) {
					if (i != n && map[i + 1][j]) {
						s_ = set(s, j, p | q);
						s_ = set(s_, j + 1, 0);
						cur->add(s_, d);//cout << s << ' ' << j << ' ' << s_ << endl;
					}
					if (j != m && map[i][j + 1]) {
						s_ = set(s, j, 0);
						s_ = set(s_, j + 1, p | q);
						cur->add(s_, d);//cout << s << ' ' << j << ' ' << s_ << endl;
					}
				}
				else if (p == 1 && q == 1) {
					int t = 0, pos;
					FOR(k, j + 1, m + 1) {
						if ((s & get(k)) >> ((k - 1) << 1) == 1) ++t;
						else if ((s & get(k)) >> ((k - 1) << 1) == 2) --t;
						if (!t) {
							pos = k;
							break;
						}
					}
					s_ = set(s, j, 0);
					s_ = set(s_, j + 1, 0);
					s_ = set(s_, pos, 1);
					cur->add(s_, d);//cout << s << ' ' << j << ' ' << pos << ' ' << s_ << endl;
				}
				else if (p == 2 && q == 2) {
					int t = 0, pos;
					for (int k = j; k; --k) {
						if ((s & get(k)) >> ((k - 1) << 1) == 2) ++t;
						else if ((s & get(k)) >> ((k - 1) << 1) == 1) --t;
						if (!t) {
							pos = k;
							break;
						}
					}
					s_ = set(s, j, 0);
					s_ = set(s_, j + 1, 0);
					s_ = set(s_, pos, 2);
					cur->add(s_, d);//cout << s << ' ' << j << ' ' << pos << ' ' << s_ << endl;
				}
				else if (p == 1 && q == 2) {//cout << i << ' ' << j << ' ' << s << endl;
					if (i == enx && j == eny) {//cout << i << ' ' << j << ' ' << s << endl;
						s_ = set(s, j, 0);
						s_ = set(s_, j + 1, 0);
						cur->add(s_, d);
						break;
					}
				}
				else if (p == 2 && q == 1) {
					s_ = set(s, j, 0);
					s_ = set(s_, j + 1, 0);
					cur->add(s_, d);
				}//cout << s << ' ' << j << ' ' << s_ << endl;
			}//cout << cur->num << endl;
//			cout << i << ' ' << j << ' ' << cur->num << endl;
//			REP(k, cur->num) cout << cur->stt[k] << ' ';
//			cout << endl << endl;
			if (i == enx && j == eny) break;
		}
		if (i == enx) break;
		REP(j, cur->num) {
			cur->stt[j] <<= 2;
		}
	}
	//cout << cur->num << endl;
	if (cur->num) printf("%llu\n", cur->ans[0]);
	else puts("0");
}

int main() {
//	setIO("ural1519");
	init();
	solve();
	return 0;
}
