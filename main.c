#include "compare.h"
#include <stdio.h>
#include <stdlib.h>


//#include "test-t.h"
#define MAP_SIZE 256

int main(int argc, char** argv)
{
	int (*compare) (const void*, const void*);
	int (**map)    (const void*, const void*);
	int i;
	int result = 0;
	void *a = NULL;
	void *b = NULL;

	map = malloc (sizeof(int (*) (const void*, const void*)) * MAP_SIZE);

	for (i = 0; i < MAP_SIZE; i++)
	{
		map[i] = NULL;
	}

	map ['i'] = intcmp;
	/*
	map ['f'] = floatcmp;
	map ['d'] = dblcmp;
	map ['c'] = charcmp;
	map ['a'] = alphacmp;
	*/

	if (argc != 4)
	{
		printf ("Usage: %s <function> <value_a> <value_b>\n", argv[0]);
		
		if (map)
			free (map);

		exit (1);
	}
	else
	{
		compare = map[(int) (argv[1][0])];

		if(argv[1][0] == 'i')
		{
			int tmp = 0;

			a = malloc (sizeof(int));
			b = malloc (sizeof(int));
	
			/// TODO : CHANGE THIS TO A FUNCTION POINTER
			/// THAT POINT TO A FUNCTION THAT CONVERTS
			/// STRING TO THE CORRECT NUMERICAL TYPE.
			tmp = atoi (argv[2]);
			memcpy (a, &tmp, sizeof(int));

			tmp = atoi (argv[3]);
			memcpy (b, &tmp, sizeof(int));

		}

	}

	if (compare)
	{
		result = compare (a, b);
		printf("compare (%s, %s) = %d", argv[2], argv[3], result);
	}

	if (map)
		free (map);
	if (a)
		free (a);
	if (b)
		free (b);

	return 0;
}
