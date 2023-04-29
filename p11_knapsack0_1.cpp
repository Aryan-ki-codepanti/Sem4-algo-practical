#include <iostream>
using namespace std;

void trace_solution(int values[], int weights[], int n, int W){}

int knapsack_prob(int values[], int weights[], int n, int W)
{
    int dp[n + 1][W + 1];

    // Setting 0 for col W = 0 (no knapsack capacity)
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    // Setting 0 for row n = 0 (no items)
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {

            // w <  wi
            if (j < weights[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], // inclusion
                               dp[i - 1][j]);                                 // exclusion
        }
    }

    return dp[n][W];
}

int main()
{
    int W, n;
    cout << "Enter n (#items ) and W(knapsack size)" << endl;
    cin >> n >> W;
    int values[n];
    int weights[n];

    cout << "Enter values" << endl;
    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << "Enter weights" << endl;
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int opt_sol = knapsack_prob(values, weights, n, W);
    cout << "Max profit/value : " << opt_sol;
    return 0;
}

/*
4 8
2 3 1 4
3 4 6 5
*/