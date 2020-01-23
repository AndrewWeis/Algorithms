// dynamic array with diferent ways to adding or removing elements

#include <iostream>

using namespace std;

void FillArray(int* const arr, const int size) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 9;
}

void ShowArray(const int* const arr, const int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void push_back(int*& arr, int& size, const int value)
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
		newArray[i] = arr[i];

	newArray[size++] = value;
	delete[] arr;
	arr = newArray;
}

void push_up(int*& arr, int& size, const int value)
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
		newArray[i + 1] = arr[i];

	size++;
	newArray[0] = value;
	delete[] arr;
	arr = newArray;
}

void pop_up(int*& arr, int& size)
{
	int* newArray = new int[--size];

	for (int i = 0; i < size; i++)
		newArray[i] = arr[i + 1];

	delete[] arr;
	arr = newArray;
}

void pop_back(int*& arr, int& size)
{
	int* newArray = new int[--size];
	for (int i = 0; i < size; i++)
		newArray[i] = arr[i];

	delete[] arr;
	arr = newArray;
}

void pop_index(int*& arr, int& size, const int index) 
{
	int* newArray = new int[size - 1];

	for (int i = 0; i < index; i++)
		newArray[i] = arr[i];

	for (int i = index + 1; i < size; i++)
		newArray[i-1] = arr[i];

	size--;
	delete[] arr;
	arr = newArray;
}

void push_index(int*& arr, int& size, const int value, const int index)
{
	int* newArray = new int[++size];

	for (int i = 0; i < index; i++)
		newArray[i] = arr[i];

	newArray[index] = value;

	for (int i = index; i < size; i++)
		newArray[i+1] = arr[i];
	
	delete[] arr;
	arr = newArray;
}

void pop_range(int*& arr, int& size, const int left, const int right) 
{
	int elements = right - left + 1;

	int* newArray = new int[size - elements];

	for (int i = 0; i < left; i++)
		newArray[i] = arr[i];

	for (int i = right + 1; i < size; i++)
		newArray[i - elements] = arr[i];

	size -= elements;
	delete[] arr;
	arr = newArray;
}

int main() 
{	
	int size = 7; int id = 2; int value = 0;
	int left = 2; int right = 4;
	int* arr = new int[size];

	FillArray(arr, size);
	ShowArray(arr, size);

	push_back(arr, size, value);
	ShowArray(arr, size);
	
	push_up(arr, size, value);
	ShowArray(arr, size);

	push_index(arr, size, value, id);
	ShowArray(arr, size);

	pop_index(arr, size, id);
	ShowArray(arr, size);

	pop_back(arr, size);
	ShowArray(arr, size);

	pop_up(arr, size);
	ShowArray(arr, size);

	pop_range(arr, size, left, right);
	ShowArray(arr, size);

	delete[] arr;

	return 0;
}
