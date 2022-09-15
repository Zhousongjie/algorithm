#include <bits/stdc++.h>
using namespace std;
template <class T>
int Part(T A[], int low, int high);
template <class T>
void QuickSort(T A[], int low, int high);

int main()
{
    int const n(5);
    int a[n];
    cout << "Input " << n << " numbers please:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    QuickSort(a, 0, n - 1);
    cout << "The sorted array is" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

template <class T>
int Part(T A[], int low, int high)
{
    T pivot = A[low]; //第一个元素作为基准
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;

    return low;
}

template <class T>
void QuickSort(T A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Part(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}
