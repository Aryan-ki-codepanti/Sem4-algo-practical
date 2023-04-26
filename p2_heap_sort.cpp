#include <iostream>
using namespace std;

class Heap
{

    int *arr, n, heapsize;

public:
    Heap(int n)
    {
        this->n = n;
        arr = new int[n];
        heapsize = 0;
    }

    void input_arr()
    {
        cout << "Enter elements" << endl;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void max_heapify(int i)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heapsize && arr[largest] < arr[l])
            largest = l;
        if (r < heapsize && arr[largest] < arr[r])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            max_heapify(largest);
        }
    }

    void build_max_heap()
    {
        heapsize = n;
        for (int i = n / 2; i >= 0; i--)
            max_heapify(i);
    }

    void heap_sort()
    {
        build_max_heap();
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapsize--;
            max_heapify(0);
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    Heap h(n);
    h.input_arr();

    cout << "Original array: ";
    h.display();
    h.heap_sort();

    cout << "Sorted array: ";
    h.display();
    return 0;
}

/*

5
4 2 -1 0 3
*/