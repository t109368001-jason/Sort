#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void BubbleSort_b(long array[], long size);
void BubbleSort_b1(long array[], long size);
void BubbleSort_b2(long array[], long size);
void QuickSort_n(long array[], long size);
void QuickSort_n_SubF(long array[], long start, long end);
void InsertionSort(long array[], long size);
void Insertion(long array[], long source, long destination);
void SelectionSort(long array[], long size);
void ShowArray(long array[], long size);
long get_minimum(long array[], long start, long end);
long get_len(long num, long base);

long main(void)
{
	long num[SIZE];
	char mode = "";
	long i;

	while (mode != -1)
	{
		printf("Enter b(bubble_normal) or c(bubble_fix_1) or d(bubble_fix_2) or q(quick) or i(insertion) or s(selection) for toptic:");
		mode = getchar();
		fflush(stdin);
		system("cls");
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

		switch (mode)
		{
		case 'b':
			ShowArray(num, SIZE);
			BubbleSort_b(num, SIZE);
			//ShowArray(num, SIZE);
			break;
		case 'c':
			ShowArray(num, SIZE);
			BubbleSort_b1(num, SIZE);
			//ShowArray(num, SIZE);
			break;
		case 'd':
			ShowArray(num, SIZE);
			BubbleSort_b2(num, SIZE);
			//ShowArray(num, SIZE);
			break;
		case 'q':
			ShowArray(num, SIZE);
			QuickSort_n(num, SIZE);
			//ShowArray(num, SIZE);
			break;
		case 'i':
			ShowArray(num, SIZE);
			InsertionSort(num, SIZE);
			ShowArray(num, SIZE);
			break;
		case 's':
			ShowArray(num, SIZE);
			SelectionSort(num, SIZE);
			//ShowArray(num, SIZE);
			break;
		}
	}
	system("pause");
	return 0;
}

void BubbleSort_b(long array[], long size)
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
		ShowArray(array, size);
	}
}

void BubbleSort_b1(long array[], long size)
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
		ShowArray(array, size);
	}
}

void BubbleSort_b2(long array[], long size)
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
		ShowArray(array, size);
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

void InsertionSort(long array[], long size)
{
	for (long i = 1; i < size; i++)
	{
		for (long j = i - 1; j >= 0; j--)
		{
			if (array[j] < array[i])
			{
				Insertion(array, i, j + 1);
				break;
			}
			else if (j == 0)
			{
				Insertion(array, i, 0);
			}
		}
		ShowArray(array, size);
	}
}

void Insertion(long array[], long source, long destination)
{
	long swap;
	swap = array[source];
	for (long i = source; i > destination; i--)
	{
		array[i] = array[i - 1];
	}
	array[destination] = swap;
}

void SelectionSort(long array[], long size)
{
	long swap;
	long element;
	for (long i = 0; i < size - 1; i++)
	{
		element = get_minimum(array, i, size - 1);
		swap = array[i];
		array[i] = array[element];
		array[element] = swap;
		ShowArray(array, size);
	}
}

void ShowArray(long array[], long size)
{
	int number = 20;
	long temp;
	if (((float)(size) / (((size - 1) / number) + 1))>(size / (((size - 1) / number) + 1)))
		temp = (size / (((size - 1) / number) + 1)) + 1;
	else
		temp = (size / (((size - 1) / number) + 1));
	for (long i = 0; i < size; i++)
	{
		printf("%*d", get_len(size, 10) + 1, array[i]);
		if ((i % temp) == (temp-1))
			printf("\n");
		else
		{
			if (i + 1 == size)
				printf("\n");
		}
	}
	printf("\n");
}
long get_minimum(long array[], long start, long end)
{
	long temp = start;
	for (long i = start; i <= end; i++)
	{
		if (array[i] < array[temp])
			temp = i;
	}
	return temp;
}

long get_len(long num, long base)
{
	if (num / base >= 1)
		return 1 + get_len(num / base, base);
	else
		return 1;
}