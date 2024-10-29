#include <bits/stdc++.h>
using namespace std;

const int inf = 1e18;
const int N = 305;

int n;
bool vis[N][N][N];
double dp[N][N][N];

double fn(int c1, int c2, int c3) {
	if (c1 == 0 && c2 == 0 && c3 == 0) return 0.;
	if (vis[c1][c2][c3]) return dp[c1][c2][c3];
	vis[c1][c2][c3] = 1;
	double &ans = dp[c1][c2][c3];
	ans = 1;
	if (c1 > 0) ans += 1. * c1 / n * fn(c1 - 1, c2, c3);
	if (c2 > 0) ans += 1. * c2 / n * fn(c1 + 1, c2 - 1, c3);
	if (c3 > 0) ans += 1. * c3 / n * fn(c1, c2 + 1, c3 - 1);
	double p0 = 1. * (n - c1 - c2 - c3) / n;
	ans /= 1. - p0;
	return ans;
}

int main() {
	cin >> n;
	vector<int> cnt(4);
	for(int i=0;i<n;i++){
		int u;
		cin >> u;
		cnt[u]++;
	}
	printf("%0.10f\n", fn(cnt[1], cnt[2], cnt[3]));
}