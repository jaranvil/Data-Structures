
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void writeToFile(int sortedArray[], string name, int time);
void runMergeSort(int randArray[]);
void merge(int arr[], int start, int middle, int end);
void mergeSort(int arr[], int start, int end);
void writeSubListFile(int arr[], int start, int end, string name);

const int arr_size = 100000;
static int randomArray[arr_size];

int main()
{
	// seed randomness
	srand(time(NULL));
	// populate array
	for (int i = 0; i < arr_size; i++)
		randomArray[i] = rand();

	writeToFile(randomArray, "unsorted", 0);

	runMergeSort(randomArray);

	_getch();
	return 0;
}

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
		writeSubListFile(arr, start, middle, "SubList1");
		// sort second half
		mergeSort(arr, middle + 1, end);

		merge(arr, start, middle, end);
	}
}

void writeToFile(int sortedArray[], string name, int time)
{
	ofstream myfile("merge_sort\\" + name + ".txt");
	if (myfile.is_open())
	{
		myfile << "Took " << time << " seconds.\n\n";
		for (int i = 0; i<arr_size; i++) {
			if (i%1000 == 0)
			{
				myfile << "\n===========================================================\n\n";
			}
			myfile << sortedArray[i] << "\n";
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

void writeSubListFile(int arr[], int start, int end, string name)
{
	std::ofstream outfile;

	outfile.open("merge_sort\\" + name + ".txt", std::ios_base::app);

	for (int i = start; i<end; i++) {
		if (i % 1000 == 0)
		{
			outfile << "\n===========================================================\n\n";
		}
		outfile << arr[i] + "\n";
	}


}