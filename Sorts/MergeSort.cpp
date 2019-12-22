#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void merge(int* a, int ak, int* b, int bk, int* res) {
	int aid = 0, bid = 0;

	while (aid < ak && bid < bk) {
		
		if (a[aid] < b[bid]) {
			res[aid + bid] = a[aid];
			aid++;
		}
		else {
			res[aid + bid] = b[bid];
			bid++;
		}
	}

	while (aid < ak)
		res[aid + bid] = a[aid++];

	while (bid < bk)
		res[aid + bid] = b[bid++];
}

void mergeSort(int ary[], int size) {
	
	int* tmp = (int*)malloc(size * sizeof(int));
	
	if (size <= 1)
		return;

	const int mid = size / 2;

	mergeSort(ary, mid);
	mergeSort(ary + mid, size - mid);
	merge(ary, mid, ary + mid, size - mid, tmp);

	memcpy(ary, tmp, size * sizeof(int));
}


int main() {
	int N;

	cout << "Enter number of elements in array: ";
	cin >> N;
	
	int* arr = (int*)malloc(N * sizeof(int));

	cout << "Enter " << N << " elements in array: ";

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	mergeSort(arr, N);

	cout << "Your sorted array: ";

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";

	free(arr);

	return 0;
}
