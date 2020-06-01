#include <stack>
using namespace std;

static int Recursive_QuickSort(int *array, int first, int last)
{
	int f = first;
	int l = last;
	int mid = array[(first + last) / 2];
	while (f <= l)
	{
		while (array[f] < mid)
			f++;
		while (array[l] > mid)
			l--;
		if (f <= l)
		{
			int count = array[f];
			array[f] = array[l];
			array[l] = count;
			f++;
			l--;
		}
	};
	if (l > first) Recursive_QuickSort(array, first, l);
	if (f < last) Recursive_QuickSort(array, f, last);
}

static int QuickSort(int *array, int first, int last)
{
	std::stack <int> stack;
	stack.push(first);
	stack.push(last);
	while (stack.size() != 0)
	{
		first = stack.top();
		stack.pop();
		last = stack.top();
		stack.pop();
		int f = first;
		int l = last;
		int mid = array[(first + last) / 2];
		while (f <= l)
		{
			while (array[f] < mid)
				f++;
			while (array[l] > mid)
				l--;
			if (f <= l)
			{
				int count = array[f];
				array[f] = array[l];
				array[l] = count;
				f++;
				l--;
			}
		};
		if (f < last)
		{
			stack.push(f);
			stack.push(last);
		}
		if (l > first)
		{
			stack.push(l);
			stack.push(first);
		}
	}
}
