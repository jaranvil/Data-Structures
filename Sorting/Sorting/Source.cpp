
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

const int arr_size = 100000;

// main random array
static int randomArray[arr_size];

// TODO pass the array around. Getting errors unless this array is a member variable
static int bubbleArr[arr_size];
static int selectionArr[arr_size];
static int insertionArr[arr_size];
static int shellArr[arr_size];

int main()
{
	// seed randomness
	srand(time(NULL));
	// populate array
	for (int i = 0; i < arr_size; i++)
		randomArray[i] = rand();	

	// perform bubble sort	
	
	//copy(std::begin(randomArray), std::end(randomArray), std::begin(newArr));
	for (int i = 0; i < arr_size; i++)
		bubbleArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		selectionArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		insertionArr[i] = randomArray[i];
	for (int i = 0; i < arr_size; i++)
		shellArr[i] = randomArray[i];
	
	bubbleSort(bubbleArr);
	selectionSort(selectionArr);
	insertionSort(insertionArr);
	shellsort(shellArr);

	// write unsorted array to file
	writeToFile(randomArray, "unsorted", 0);
	
	cout << "DONE";
	_getch();
	return 0;
}

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