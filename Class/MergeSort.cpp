#include <iostream>
using namespace std;
template <class T>
void MergeSort(T arr[], int low, int high);
template <class T>
void Merge(T arr[], int low, int mid, int high);

int main()
{
    int const n(5);
    int a[n];
    cout << "Input " << n << " numbers please:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MergeSort(a, 0, n - 1);
    cout << "The sorted array is" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i]<<" ";
    cout << endl;
}

template<class T>
void Merge(T arr[], int low, int mid, int high) {
	T *tempArr = new T[high - low + 1];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j])
			tempArr[k++] = arr[i++];
		else
			tempArr[k++] = arr[j++];
	}
	// 如果 arr[low] 到 arr[mid] 区间中的数组还没有比较完成 ，直接复制到tempArr 中
	while (i <= mid) 
		tempArr[k++] = arr[i++];

	// 如果 arr[mid+1] 到 arr[hight] 区间中的数组还没有比较完成 ，直接复制到tempArr 中
	while (j <= high)
		tempArr[k++] = arr[j++];
	
    // 比较完成之后 将原本的数组arr 下标 low-hight 对应的内容 进行改变
	i = low;
	for (int tempK = 0;(tempK < k)&&(i<=high);tempK++,i++) 
		arr[i] = tempArr[tempK];

	delete[] tempArr;
	tempArr = NULL;
	
}
/**
 *功能：拆分有序的序列两两排序-拆解结束的条件 子序列长度为1的时候
 */
template<class T>
void MergeSort(T arr[], int low, int high) {
	if (low < high) {
		int mid = (high + low) / 2;
		MergeSort(arr,low,mid);// 递归拆解左边的序列
		MergeSort(arr, mid + 1, high);// 递归拆解左边的序列
		Merge(arr, low, mid, high);// 将两个有序的子序列（arr[low至mid]、arr[mid+1至hight] 排序合并成一个新的有序列
	}
}
