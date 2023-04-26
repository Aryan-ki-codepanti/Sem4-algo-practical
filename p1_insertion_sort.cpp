#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
    insertion_sort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}

/*

5
4 2 -1 0 3
*/