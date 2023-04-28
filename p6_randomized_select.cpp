

#include <iostream>
#include <ctime>
using namespace std;

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
int randomized_partition(int arr[], int p, int r)
{
    int i = rand() % (r + 1 - p) + p;
    swap(arr[i], arr[r]);
    return partition(arr, p, r);
}

int randomized_select(int arr[], int p, int r, int i)
{
    if (p == r)
        return arr[p];
    int q = randomized_partition(arr, p, r);

    int k = q - p + 1; // no. of elements in left portion

    if (k == i)
        return arr[q];
    else if (i < k)
        return randomized_select(arr, p, q - 1, i);
    return randomized_select(arr, q + 1, r, i - k);
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, i;
    cout << "Enter n : ";
    cin >> n;
    int arr[n];

    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter i : ";
    cin >> i;
    cout << i << "th Order Statistic : " << randomized_select(arr, 0, n - 1, i);
    return 0;
}

/*

5
4 2 -1 0 3
2
*/