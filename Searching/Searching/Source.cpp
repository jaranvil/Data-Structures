#include <conio.h>
#include <iostream>
#include <ctime>
using namespace std;

// prototypes
int binarySearch(int[], int, int);
int startBinarySearch(int list[], int length);
int sequentialSearch(int[], int, int[]);

int main()
{	
	const int length = 100000;
	static int list[length];
	for (int i = 0; i < length; i++)
	{
		list[i] = i;
	}

	// sequential
	cout << "Sequential search.." << endl;
	clock_t start;
	start = clock();

	int result = sequentialSearch(list, length, list);

	std::cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	cout << "Found " << result << " matches." << endl << endl;

	// binary
	cout << "Binary search..." << endl;
	clock_t start2;
	start2 = clock();
	
	result = startBinarySearch(list, length);

	std::cout << "Time: " << (clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	cout << "Found " << result << " matches." << endl << endl;

	_getch();
	return 0;
}

// sqquential search
int sequentialSearch(int list[], int length, int target[])
{
	int matches = 0;
	for (int c = 0; c < length; c++)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i] == target[c])
				matches++;
		}
	}
	
	return matches;
}

int startBinarySearch(int list[], int length)
{
	int matches = 0;
	for (int i = 0; i < length; i++)
	{
		int result = binarySearch(list, length, list[i]);
		if (result != -1)
		{
			matches++;
		}
	}
	return matches;
}

// binarySeach non-recursive
int binarySearch(int list[], int length, int target) 
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
