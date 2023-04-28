#include <iostream>
#include <cmath>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// to get ith digit from n i: 0, 1, 2...
int digit(int n, int i)
{
    int a = n / pow(10, i);
    return a % 10;
}

// counting sort based on digit r so used digit
void counting_sort(int arr[], int n, int r = 0, int k = 9)
{

    int result[n];
    int counts[k + 1] = {0};

    // counting each element
    for (int i = 0; i < n; i++)
        counts[digit(arr[i], r)]++;

    // cumulative count
    for (int i = 1; i <= k; i++)
        counts[i] += counts[i - 1];

    for (int i = n - 1; i >= 0; i--)
        result[counts[digit(arr[i], r)]-- - 1] = arr[i];

    // inplace
    // copy result back to orignal arr
    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}

void radix_sort(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
        counting_sort(arr, n, i);
}

int main()
{

    int n, d;
    cout << "Enter n: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter d : ";
    cin >> d;

    cout << "\nOrignal array" << endl;
    display(arr, n);

    radix_sort(arr, n, d);
    cout << "\nSorted array" << endl;
    display(arr, n);
    return 0;
}

/*
7
329
457
657
839
436
720
355
3
*/