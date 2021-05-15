#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

long max(long x, long y) {
	return x > y ? x : y;
}
long min(long x, long y) {
	return x < y ? x : y;
}
void Modify(long &x, long y) {
	x = x == -1 ? y : min(x, y);
}

long get(long x){
	long s;
	for (s = 0; x; x >>= 1)
		if (1 & x)
			++s;
	return s;
}

long f[2][31][31][31][2];

int main() {
	long x, y, z, n = 0;
	//freopen("aplusb.in", "r", stdin);
	//freopen("aplusb.out", "w", stdout);
	scanf("%ld%ld%ld", &x, &y, &z);
	long a = get(x), b = get(y), c = get(z);
	x = max(x, max(y, z));
	for (; x; x >>= 1)
		++n;
	memset(f, -1, sizeof f);
	f[0][0][0][0][0] = 0;
	long cur = 0;
	for (long t = 0; t < n; ++t, cur ^= 1) {
		long aa = min(t, a), bb = min(t, b), cc = min(t, c);
		for (long i = 0; i <= aa; ++i)
			for (long j = 0; j <= bb; ++j)
				for (long k = 0; k <= cc; ++k) {
					if (f[cur][i][j][k][0] != -1) {
						long l = f[cur][i][j][k][0];
						Modify(f[cur ^ 1][i][j][k][0], l);
						if (i < a && k < c)
							Modify(f[cur ^ 1][i + 1][j][k + 1][0], l + (1 << t));
						if (i < a && j < b)
							Modify(f[cur ^ 1][i + 1][j + 1][k][1], l);
						if (j < b && k < c)
							Modify(f[cur ^ 1][i][j + 1][k + 1][0], l + (1 << t));
					}
					if(f[cur][i][j][k][1] != -1) {
						long l = f[cur][i][j][k][1];
						Modify(f[cur ^ 1][i][j][k + 1][0], l + (1 << t));
						if (i < a)
							Modify(f[cur ^ 1][i + 1][j][k][1], l);
						if (j < b)
							Modify(f[cur ^ 1][i][j + 1][k][1], l);
						if (i < a && j < b && k < c)
							Modify(f[cur ^ 1][i + 1][j + 1][k + 1][1], l + (1 << t));
                    }
				}
	}
	printf("%ld\n", f[cur][a][b][c][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
