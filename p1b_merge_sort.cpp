#include <iostream>
using namespace std;


void merge(int arr[], int n, int l, int r)
{
    int q = (l + r) / 2;

    int n1 = q - l + 1;
    int n2 = r - q;
    int left[n1], right[n2];

    // copy left portion to left[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    // copy right portion to right[]
    for (int i = 0; i < n2; i++)
        right[i] = arr[q + 1 + i];

    // merge left right to arr[l...r]
    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 || j < n2)
    {
        if (i < n1 && j < n2)
        {
            if (left[i] < right[j])
                arr[k] = left[i++];
            else
                arr[k] = right[j++];
        }
        else if (i < n1)
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }
}

void merge_sort(int arr[], int n, int l, int r)
{
    if (l >= r)
        return;

    int q = (l + r) / 2;
    merge_sort(arr, n, l, q);
    merge_sort(arr, n, q + 1, r);
    merge(arr, n, l, r);
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
    merge_sort(arr, n, 0, n - 1);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}

/*

5
4 2 -1 0 3
*/