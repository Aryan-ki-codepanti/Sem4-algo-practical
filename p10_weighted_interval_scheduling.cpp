#include <iostream>
#include <algorithm>
using namespace std;

class Interval
{
public:
    int start, finish, weight;

    Interval(int a = 0, int b = 0, int c = 0)
    {
        start = a;
        finish = b;
        weight = c;
    }
};

bool interval_comparator(Interval a, Interval b)
{
    return a.finish <= b.finish;
}

// binary search to find p(idx)
// returns p(j) acc to 1 based idx
int latest_non_overlapping_interval(Interval arr[], int n, int idx)
{
    int l = 0;
    int r = idx - 1;

    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid].finish <= arr[idx].start)
        {
            if (arr[mid + 1].finish <= arr[idx].start)
                l = mid + 1;
            else
                return mid + 1;
        }
        else
            r = mid - 1;
    }

    return 0;
}

void find_solution(int dp[], Interval arr[], int p_j[], int n, int j)
{
    if (j == 0)
        return;

    // include
    if (arr[j - 1].weight + dp[p_j[j]] >= dp[j - 1])
    {
        cout << arr[j - 1].start << " " << arr[j - 1].finish << " " << arr[j - 1].weight << endl;
        find_solution(dp, arr, p_j, n, p_j[j]);
    }
    // exclude
    else
        find_solution(dp, arr, p_j, n, j - 1);
}

int maximum_weight(Interval arr[], int n)
{
    sort(arr, arr + n, interval_comparator);
    int p_j[n + 1];
    p_j[0] = 0;

    for (int i = 0; i < n; i++)
        p_j[i + 1] = latest_non_overlapping_interval(arr, n, i);


    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i] = max(arr[i - 1].weight + dp[p_j[i]],
                    dp[i - 1]);

    cout << "\nSolution set" << endl;
    find_solution(dp, arr, p_j, n, n);
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter no. of intervals: ";
    cin >> n;

    cout << "Enter start, finish and weights" << endl;
    Interval arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].finish >> arr[i].weight;

    int soln = maximum_weight(arr, n);
    cout << "Max sum weight: " << soln;
    return 0;
}

/*
6

2 6 4
1 4 2
3 10 7
5 7 4
9 12 1
8 11 2
*/