#include <iostream>
#include "Search.cpp"
#include "Sort.cpp"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	const int length = 10000;
	int firstarray[length];
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		firstarray[i] = rand() % 2001 - 1000;
	cout << "item index 47: " << Search(firstarray, 47, length);
	cout << endl << endl;
	const int length_2 = 100;
	int secondarray[length_2];
	srand(time(NULL));
	for (int i = 0; i < length_2; i++)
		secondarray[i] = rand() % 21 - 10;
	for (int i = 0; i < 50; i++)
		cout << secondarray[i] << " ";
	QuickSort(secondarray, 0, length_2 - 1);
	for (int i = 0; i < 50; i++)
		cout << secondarray[i] << " ";
	cout << "BSearch item 23, its index: " << BSearch(secondarray, 23, 0, length_2 - 1);
	cout << endl << endl;
	const int length_3 = 100000;
	int testArray[length_3];
	int testArraySort[length_3];
	srand(time(NULL));
	for (int i = 0; i < length_3; i++)
	{
		testArray[i] = rand();
		testArraySort[i] = rand();
	}
	QuickSort(testArraySort, 0, length_3 - 1);
	long t1, t2;

	t1 = clock();
	for (int i = 0; i < 10000; i++)
		Search(testArray, rand(), length_3);
	t2 = clock();
	cout << "Search in unsorted array: " << t2 - t1 << endl;

	t1 = clock();
	for (int i = 0; i < 10000; i++)
		Search(testArraySort, rand(), length_3);
	t2 = clock();
	cout << "Search in sorted array: " << t2 - t1 << endl;

	t1 = clock();
	for (int i = 0; i < 10000; i++)
		BSearch(testArray, rand(), 0, length_3 - 1);
	t2 = clock();
	cout << "Binary search in unsorted array: " << t2 - t1 << endl;

	t1 = clock();
	for (int i = 0; i < 10000; i++)
		BSearch(testArraySort, rand(), 0, length_3 - 1);
	t2 = clock();
	cout << "Binary searc in sorted array: " << t2 - t1 << endl;
}
