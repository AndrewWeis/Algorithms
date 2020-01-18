void memcpy_(int* fArr, const int* sArr, size_t size) {

	delete[] fArr;

	fArr = new int[size];

	for (int i = 0; i < size; i++)
		fArr[i] = sArr[i];
}
