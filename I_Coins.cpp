#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));
    dp[0][0] = 1.0; 

    // Fill the dp table
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i-1][j] * (1 - p[i-1]);  // Case when the i-th coin is tails
            if (j > 0) {
                dp[i][j] += dp[i-1][j-1] * p[i-1];  // Case when the i-th coin is heads
            }
        }
    }
    double result = 0.0;
    for (int j = (N / 2) + 1; j <= N; j++) {
        result += dp[N][j];
    }

    cout << fixed << setprecision(9) << result << endl;

    return 0;
}
