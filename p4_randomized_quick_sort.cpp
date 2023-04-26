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

void randomized_quick_sort(int arr[], int p, int r)
{
    if (p >= r)
        return;
    int q = randomized_partition(arr, p, r);
    randomized_quick_sort(arr, p, q - 1);
    randomized_quick_sort(arr, q + 1, r);
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    display(arr, n);
    randomized_quick_sort(arr, 0, n - 1);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}

/*

5
4 2 -1 0 3
*/