#include <iostream>
using namespace std;

static int Search(int *array, int value, int n)
{
	for (int i = 0; i < n; i++)
		if (array[i] == value) return i;
	else return -1;
}

static int BSearch(int *array, int value, int left, int right)
{
	int middle;
	while (left + 1 < right)
	{
		middle = (left + right) / 2;
		if (value == array[middle])
			return middle;

		if (value > array[middle])
			left = middle;
		else right = middle;
	}
}

static int Recursive_BSearch(int *array, int value, int left, int right)
{
	int middle = (left + right) / 2;
	if (value < array[middle])
		Recursive_BSearch(array, value, left, middle - 1);
	else if (value > array[middle])
		Recursive_BSearch(array, value, middle + 1, right);
	else return middle;

	if (left > right) return -1;
}