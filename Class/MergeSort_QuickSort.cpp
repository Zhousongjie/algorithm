// 实现MergeSortL() 和 QuickSort()
// 测试数据使用rand()生成的随机数
// 作者：吉宗诚
// 单位：中科院计算与通信工程学院
// 时间：2008-10-18


#include "iostream"

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

//QuickSort
int Partition(int m, int p);
void QuickSort(int p, int q);
void InsertSort(int p,int q);
void initAq(); // 随机生成初始化Aq数组
void printAq_Sorted(); // 输出通过QuickSort排序后的Aq数组
int Aq[MAX_N];




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




//QuickSort
int Partition(int m, int p) {
	int v = Aq[m];
	int i = m;
	
	while (true) {
		while (Aq[i] <= v) i++; //search from left to right
		while (Aq[p] > v && p > m) p--; //search from right to left
		if (i < p) {
			int temp = Aq[i];
			Aq[i] = Aq[p];
			Aq[p] = temp;
		}
		else break;
	}

	Aq[m] = Aq[p], Aq[p] = v; // 划分元素在位置p

	return p;
}

void QuickSort(int p, int q) {
	if (p < q) {
		if (q - p < Small) {
			InsertSort(p, q);
		}
		else {
			int x = Partition(p, q);
			QuickSort(p, x - 1);
			QuickSort(x + 1, q);
		}
	}

	return ;
}

void InsertSort(int p,int q) {
	for (int i = p; i <= q; i++) {
		for (int j = i; j <= q; j++) {
			if (Aq[j] < Aq[i]) {
				int temp = Aq[i];
				Aq[i] = Aq[j];
				Aq[j] = temp;
			}
		}
	}
	return ;
}

void initAq() {
	int i;
	for (i = 0; i < MAX_N; i++) Aq[i] = (int)rand();

	cout << "The original array Aq is:" << endl;
	for (i = 0; i < MAX_N; i++) cout << Aq[i] << " ";
	cout << endl;

	return ;
}

void printAq_Sorted() {
	cout << "After QuickSort, the array Aq is:" << endl;
	for (int i = 0; i < MAX_N; i++) cout << Aq[i] << " ";
	cout << endl;
	
	return ;
}


int main() {
	initAL_Link();
	MergeSortL(1, MAX_N);
	printAL_Sorted();

	cout << endl;

	initAq();
	QuickSort(0, MAX_N-1);
	printAq_Sorted();

	return 0;
}