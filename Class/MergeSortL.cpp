#include <iostream>
using namespace std;
const int MAX_N = 12;



// MergeSortL
int MergeSortL(int low, int high); // int p
int MergeL(int q, int r); // 由地址链接表q和r构造新的链接表p. 返回两组归并后的地址排序
int InsertSortL(int low, int high); // int p
void initAL_Link(); // 随机初始化AL, Link数组
void printAL_Sorted(); // 输出通过MergeSortL排序后的AL数组
int AL[MAX_N + 1]; // 比较特殊，第0个不用
int Link[MAX_N + 1]; // linked list
const int Small = 16; // 设定子问题的最小规模Small

// MergeSortL
int MergeSortL(int low, int high) {
	if (high - low < Small) {
		return InsertSortL(low, high);
	}
	else {
		int mid = (low + high) / 2;
		int q = MergeSortL(low, mid); // 返回 q 表
		int r = MergeSortL(mid + 1, high); // 返回 r 表
		return MergeL(q, r); // 将表q 和 r 合并成表 p
	}
}

int MergeL(int q, int r) {
	int i = q, j = r, k = 0;

	while (i != 0 && j != 0) { // 当两个表皆非空时
		if (AL[i] <= AL[j]) {
			Link[k] = i, k = i, i = Link[i];
		}
		else {
			Link[k] = j, k = j, j = Link[j];
		}
	}

	if (i == 0) Link[k] = j;
	else Link[k] = i;

	return Link[0];
}

int InsertSortL(int low, int high) {
	for (int i = low; i <= high; i++) {
		for (int j = i; j <= high; j++) {
			if (AL[j] < AL[i]) {
				int temp = AL[i];
				AL[i] = AL[j];
				AL[j] = temp;
			}
		}
	}
	Link[high] = 0;
	
	return low;
}

void initAL_Link() {
	int i;
	for (i = 1; i <= MAX_N; i++) {
		AL[i] = (int)rand();
		Link[i] = i + 1;
	}
	Link[0] = 1;
	Link[MAX_N] = 0;

	cout << "The original array AL is:" << endl;
	for (i = 1; i <= MAX_N; i++) cout << AL[i] << " ";
	cout << endl;

	return ;
}

void printAL_Sorted() {
	cout << "After MergeSortL, the array AL is:" << endl;

	int i = 0;
	while (true) {
		int temp = AL[i];
		i = Link[i];
		if (i == 0) break;
		cout << AL[i] << " ";
	}
	cout << endl;

	return ;
}


int main() {
	initAL_Link();
	MergeSortL(1, MAX_N);
	printAL_Sorted();
}