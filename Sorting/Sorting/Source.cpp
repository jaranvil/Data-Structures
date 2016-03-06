
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;


void writeToFile(int sortedArray[], string name, int time);
void bubbleSort(int randArray[]);
void selectionSort(int randArray[]);
void insertionSort(int randArray[]);
void shellsort(int randArray[]);
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int middle, int end);
void runMergeSort(int[]);
void quickSort(int arr[], int left, int right);
void runQuickSort();

const int arr_size = 100000;

// main random array
static int randomArray[arr_size];

// TODO pass the array around. Getting errors unless this array is a member variable
static int bubbleArr[arr_size];
static int selectionArr[arr_size];
static int insertionArr[arr_size];
static int shellArr[arr_size];
static int mergeArr[arr_size];
static int quickArr[arr_size];

int main()
{
	// seed randomness
	srand(time(NULL));
	// populate array
	for (int i = 0; i < arr_size; i++)
		randomArray[i] = rand();	

	//copy(std::begin(randomArray), std::end(randomArray), std::begin(newArr));
	for (int i = 0; i < arr_size; i++)
		bubbleArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		selectionArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		insertionArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		shellArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		mergeArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		quickArr[i] = randomArray[i];

	bubbleSort(bubbleArr);
	selectionSort(selectionArr);
	insertionSort(insertionArr);
	shellsort(shellArr);
	runMergeSort(mergeArr);
	runQuickSort();

	// write unsorted array to file
	writeToFile(randomArray, "unsorted", 0);
	
	cout << "DONE";
	_getch();
	return 0;
}

/*************
*	Bubble
**************/

void bubbleSort(int randArray[])
{
	cout << "Starting bubble sort... ";
	time_t startTime = time(nullptr);

	int swap;
	for (int x = 0; x < arr_size; x++)
	{
		for (int y = 0; y < arr_size - x; y++)
		{
			if (randArray[y] > randArray[y + 1]) 
			{
				swap = randArray[y];
				randArray[y] = randArray[y + 1];
				randArray[y + 1] = swap;
			}
		}
	}

	time_t endTime = time(nullptr);
	int seconds = endTime - startTime;
	cout << seconds << " seconds elasped." << endl;

	writeToFile(randArray, "bubble", seconds);
}

/*************
*	Selection
**************/

void selectionSort(int randArray[])
{
	cout << "Starting selection sort... ";
	time_t startTime = time(nullptr);

	int smallestNumFound = arr_size; // start with an aribratry large number
	int positionOfSmallNum;

	// loop through each number position
	for (int i = 0; i < arr_size; i++) 
	{
		smallestNumFound = arr_size; // reset int to a large num
		// find smallest number between current position and end
		for (int z = i; z < arr_size; z++) 
		{
			// find smallest number to the right of current position
			if (randArray[z] < smallestNumFound)
			{
				smallestNumFound = randArray[z];
				positionOfSmallNum = z;
			}	
		}
		// swap current position with smallest number and move to next position
		randArray[positionOfSmallNum] = randArray[i];
		randArray[i] = smallestNumFound;
	}

	time_t endTime = time(nullptr);
	int seconds = endTime - startTime;
	cout << seconds << " seconds elasped." << endl;

	writeToFile(randArray, "selection", seconds);
}

/*************
*	Insertion
**************/

void insertionSort(int randArray[]) 
{
	cout << "Starting insertion sort... ";
	time_t startTime = time(nullptr);

	int j;
	int temp;

	// foreach number is array
	for (int i = 0; i < arr_size; i++) {
		j = i;
		// look to the left of current position
		while (j > 0 && randArray[j] < randArray[j - 1]) {
			//swap values that are out of order
			temp = randArray[j];
			randArray[j] = randArray[j - 1];
			randArray[j - 1] = temp;
			j--;
		}
	}

	time_t endTime = time(nullptr);
	int seconds = endTime - startTime;
	cout << seconds << " seconds elasped." << endl;

	writeToFile(randArray, "insertion", seconds);
}

/*************
*	Shell
**************/

void shellsort(int randArray[])
{
	cout << "Starting shell sort... ";
	time_t startTime = time(nullptr);

	int gap, i, j, temp;
	for (gap = arr_size / 2; gap > 0; gap /= 2)
		for (i = gap; i < arr_size; i++)
			for (j = i - gap; j >= 0 && randArray[j] > randArray[j + gap]; j -= gap) {
				temp = randArray[j];
				randArray[j] = randArray[j + gap];
				randArray[j + gap] = temp;
			}

	time_t endTime = time(nullptr);
	int seconds = endTime - startTime;
	cout << seconds << " seconds elasped." << endl;

	writeToFile(randArray, "shell", seconds);
}

/*************
*	Merge
**************/

void runMergeSort(int randArray[])
{
	cout << "Starting merge sort... ";
	time_t startTime = time(nullptr);

	mergeSort(randArray, 0, arr_size - 1);

	time_t endTime = time(nullptr);
	int seconds = endTime - startTime;
	cout << seconds << " seconds elasped." << endl;

	writeToFile(randArray, "merge", seconds);
}

void merge(int arr[], int start, int middle, int end)
{
	int i, j, k, c[arr_size];
	i = start;
	k = start;
	j = middle + 1;
	while (i <= middle && j <= end)
	{
		if (arr[i] < arr[j])
		{
			c[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			c[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= middle)
	{
		c[k] = arr[i];
		k++;
		i++;
	}
	while (j <= end)
	{
		c[k] = arr[j];
		k++;
		j++;
	}
	for (i = start; i < k; i++)
	{
		arr[i] = c[i];
	}
}

void mergeSort(int arr[], int start, int end)
{
	if (start < end)
	{
		//int middle = (start + end) / 2;
		int middle = start + (end - start) / 2;

		// Sort first half
		mergeSort(arr, start, middle);
		// sort second half
		mergeSort(arr, middle + 1, end);

		merge(arr, start, middle, end);
	}
}

// Quick sort

void runQuickSort()
{
	cout << "Starting quick sort... ";
	time_t startTime = time(nullptr);

	quickSort(quickArr, 0, arr_size);

	time_t endTime = time(nullptr);
	int seconds = endTime - startTime;
	cout << seconds << " seconds elasped." << endl;

	writeToFile(quickArr, "quick", seconds);
}

void quickSort(int arr[], int left, int right) 
{
	int i = left;
	int j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	// more values to left or right of pivot pivot point whether they are greater or smaller
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	// run recursively to sort entire array
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);

	
}

void writeToFile(int sortedArray[], string name, int time)
{
	ofstream myfile(name + ".txt");
	if (myfile.is_open())
	{		
		myfile << "Took " << time << " seconds.\n\n";
		for (int i=0; i<100000; i++) {
			myfile << sortedArray[i] << "\n";
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}