#include <conio.h>
#include <iostream>
#include <ctime>
using namespace std;

// prototypes
int binarySearch(int[], int, int);
int sequentialSearch(int[], int, int);

int main()
{	
	const int length = 1000;
	static int list[length];
	for (int i = 0; i < length; i++)
	{
		list[i] = i;
	}

	// sequential
	cout << "Sequential search.." << endl;
	clock_t start;
	start = clock();

	int result = sequentialSearch(list, length, 864);

	std::cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	cout << result << endl << endl;

	// binary
	cout << "Binary search..." << endl;
	clock_t start2;
	start2 = clock();
	
	result = binarySearch(list, 864, length);

	std::cout << "Time: " << (clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	cout << result;

	_getch();
	return 0;
}

// sqquential search
int sequentialSearch(int list[], int length, int target)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == target)
			return list[i];
	}
	return -1;
}

// binarySeach non-recursive
int binarySearch(int list[], int target, int length) 
{
	int low = 0;
	int high = length - 1;
	while (low <= high) 
	{		
		int mid = (low + high) / 2;
		if (list[mid] == target) return mid;
		else if (list[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
