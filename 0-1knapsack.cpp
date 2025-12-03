#include <iostream>
using namespace std;
class Solution {
private:
    int func(int wt[], int val[], int ind, int W, int dp[][1001]) {

        if (ind < 0 || W == 0)
            return 0;

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int notTaken = func(wt, val, ind - 1, W, dp);
        int taken = 0;

        if (wt[ind] <= W)
            taken = val[ind] + func(wt, val, ind - 1, W - wt[ind], dp);

        return dp[ind][W] = max(notTaken, taken);
    }
public:
    int knapsack01(int wt[], int val[], int n, int W) {
        // dp[n][W+1] initialized with -1
        static int dp[1001][1001];
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= W; j++)
                dp[i][j] = -1;

        return func(wt, val, n - 1, W, dp);
    }
};

int main() {

    int wt[]  = {1, 2, 4, 5};
    int val[] = {5, 4, 8, 6};
    int W = 5;
    int n = sizeof(wt) / sizeof(wt[0]);

    Solution sol;
    int ans = sol.knapsack01(wt, val, n, W);
    cout << "The Maximum value of items is " << ans << endl;
    return 0;
}
