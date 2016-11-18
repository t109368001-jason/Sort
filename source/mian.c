#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void BubbleSort_n(long array[], long size);
void BubbleSort_a(long array[], long size);
void BubbleSort_b(long array[], long size);
void QuickSort_n(long array[], long size);
void QuickSort_n_SubF(long array[], long start, long end); 
void InsertionSort(int array[], int size);
void Insertion(int array[], int source, int destination);
void SelectionSort(int array[], int size); 
int minimum(int array[], int start, int end);

long totaltimes;

int main(void)
{
	long num[SIZE];
	char mode = 0;
	long i;
	long elapse;
	long start_time;
	long total = 0;

	while (mode != -1)
	{
		totaltimes = 0;
		printf("Enter a or b or n or q for toptic:");
		mode = getchar();
		fflush(stdin);
		total = 0;
		srand(time(NULL));
		for (i = 0; i < SIZE; i++)
		{
			long same = 1;
			while (same)
			{
				same = 0;
				num[i] = 1 + rand() % SIZE;
				for (long j = i - 1; j >= 0; j--)
				{
					if (num[i] == num[j])
						same = 1;
				}
			}
		}

		for (i = 0; i < SIZE; i++)
		{
			printf("%2d:%3d  ", i, num[i]);
			if (i % 5 == 4)
				printf("\n");
		}
		printf("\n");

		if (mode == 'a')
			BubbleSort_a(num, SIZE);
		else if (mode == 'b')
			BubbleSort_b(num, SIZE);
		else if (mode == 'n')
			BubbleSort_n(num, SIZE);
		else if (mode == 'q')
			QuickSort_n(num, SIZE);
		else if (mode == 'i')
			InsertionSort(num, SIZE);
		else if (mode == 's')
			SelectionSort(num, SIZE);

		for (i = 0; i < SIZE; i++)
		{
			printf("%2d:%3d  ", i, num[i]);
			if (i % 5 == 4)
				printf("\n");
		}
	}
	system("pause");
	return 0;
}

void BubbleSort_n(long array[], long size)
{
	long swap;
	long i;
	long j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j]>array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
		}
	}
}

void BubbleSort_a(long array[], long size)
{
	long times = size - 1;
	long swap;
	long i;
	long j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < times; j++)
		{
			if (array[j]>array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
		}
		times--;
	}
}

void BubbleSort_b(long array[], long size)
{
	long times = size - 1;
	long swap;
	long keep = 1;
	long i;
	long j;

	while (keep == 1)
	{
		keep = 0;
		for (j = 0; j < times; j++)
		{
			if (array[j]>array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				keep = 1;
			}
		}
		times--;
	}
}

void QuickSort_n(long array[], long size)
{
	QuickSort_n_SubF(array, 0, size - 1);
}

void QuickSort_n_SubF(long array[], long start, long end)
{
	long swap;
	long less = end;
	long greater = start + 1;
	while (greater <= less)
	{
		if (array[greater] < array[start])
			greater++;
		if (array[less] > array[start])
			less--;
		if (greater > less)
		{
			if (less != start)
			{
				swap = array[start];
				array[start] = array[less];
				array[less] = swap;
				if ((less - 1) != start)
					QuickSort_n_SubF(array, start, less - 1);
			}
			QuickSort_n_SubF(array, greater, end);
		}
		else
		{
			if (array[greater] > array[start] && array[start] > array[less])
			{
				swap = array[greater];
				array[greater] = array[less];
				array[less] = swap;
			}
		}
	}
}

void InsertionSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (array[j] < array[i])
			{
				Insertion(array, i, j+1);
				break;
			}
			else if (j == 0)
			{
				Insertion(array, i, 0);
			}
		}
	}
}

void Insertion(int array[], int source, int destination)
{
	int swap;
	swap = array[source];
	for (int i = source; i > destination; i--)
	{
		array[i] = array[i - 1];
	}
	array[destination] = swap;
}

void SelectionSort(int array[], int size)
{
	int swap;
	int element;
	for (int i = 0; i < size - 1; i++)
	{
		element = minimum(array, i,size-1);
		swap = array[i];
		array[i] = array[element];
		array[element] = swap;
	}
}

int minimum(int array[], int start,int end)
{
	int temp = start;
	for (int i = start; i <= end; i++)
	{
		if (array[i] < array[temp])
			temp = i;
	}
	return temp;
}