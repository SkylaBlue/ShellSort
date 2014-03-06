/*
	Shell.c
	Shell sort implementation in C
	
	h = 1
	while h < n, h = 3*h + 1
		while h > 0,
			h = h / 3
			for k = 1:h, insertion sort a[k:h:n]
			-> invariant: each h-sub-array is sorted
	end
*/

#include <stdio.h>

typedef unsigned int UINT;

void shell(int array[], UINT size)
{
	UINT m = 1;
	
	while (m <= size)
	{
		m = 3 * m + 1;
	}

	while (m > 0)
	{
		m = m / 3;
		UINT k;
		for (k = 1; k < m; k++)
		{
			/*	Insertion Sort */
			UINT i;
			for (i = 1; i < size; i++)
			{
				UINT j;
				for (j = i; j > 0 && array[j-1] > array[j]; j--)
				{
					// Xor swap
					array[j]   ^= array[j-1];
					array[j-1] ^= array[j];
					array[j]   ^= array[j-1];
				}
			}
		}
	}
}

int main()
{
	
	int array[10] = {9, 5, 3, 1, 12, 4, 200, 150, 99, 20};
	UINT size = sizeof(array) / sizeof(array[0]);
	
	shell(array, size);
	
	UINT i;
	for (i = 0; i < size; i++)
	{
		printf("%i\n", array[i]);
	}
	
	return 0;
}
