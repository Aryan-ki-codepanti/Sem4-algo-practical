#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<float> &arr, int n)
{
    int j;
    float key;
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

void bucket_sort(float arr[], int n)
{

    vector<float> buckets[n];

    // inserting elements to the bucket
    int bucket;
    for (int i = 0; i < n; i++)
    {
        bucket = (int)(n * arr[i]);
        buckets[bucket].push_back(arr[i]);
    }

    // Sorting the buckets with insertion sort
    for (int i = 0; i < n; i++)
        insertion_sort(buckets[i], buckets[i].size());

    // concatenating into single array
    int j = 0;
    for (int i = 0; i < n; i++)
        for (auto &k : buckets[i])
            arr[j++] = k;


}

void display(float arr[], int n)
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
    float arr[n];

    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    display(arr, n);
    bucket_sort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}

/*
6
.3 .6 .04 .23 .111 .4
*/