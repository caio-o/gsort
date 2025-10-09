#include <stdio.h>
#include <stdlib.h>

#include "compare.h"
#include "treatargs.h"

//#include "test-t.h"
#define MAP_SIZE 256

int main(int argc, char** argv)
{
	//int (*compare) (const void*, const void*);
	int (**map)    (const void*, const void*);
	int i;
	//int result = 0;
	//int tmpi = 0;
	//float tmpf = 0.0F;
	//double tmplf = 0.0L;
	//char tmpc = '\0';

	void *a = NULL;
	void *b = NULL;

	map = malloc (sizeof(int (*) (const void*, const void*)) * MAP_SIZE);

	for (i = 0; i < MAP_SIZE; i++)
	{
		
		map[i] = NULL;
	}

	map ['i'] = intcmp;
	map ['f'] = floatcmp;
	map ['d'] = dblcmp;
	map ['c'] = charcmp;
	map ['a'] = alphacmp;
	
	treatArgs (argc, argv);
	
	/*
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

		switch(argv[1][0])
		{
		case 'i':
			tmpi = 0;

			a = malloc (sizeof(int));
			b = malloc (sizeof(int));
	
			/// TODO : CHANGE THIS TO A FUNCTION POINTER
			/// THAT POINT TO A FUNCTION THAT CONVERTS
			/// STRING TO THE CORRECT NUMERICAL TYPE.
			tmpi = atoi (argv[2]);
			memcpy (a, &tmpi, sizeof(int));

			tmpi = atoi (argv[3]);
			memcpy (b, &tmpi, sizeof(int));
		break;

		case 'f':
			tmpf = 0;

			a = malloc (sizeof(float));
			b = malloc (sizeof(float));
	
			/// TODO : CHANGE THIS TO A FUNCTION POINTER
			/// THAT POINT TO A FUNCTION THAT CONVERTS
			/// STRING TO THE CORRECT NUMERICAL TYPE.
			tmpf = atof (argv[2]);
			memcpy (a, &tmpf, sizeof(float));

			tmpf = atof (argv[3]);
			memcpy (b, &tmpf, sizeof(float));
			
		break;
		
		case 'd':
			tmplf = 0;

			a = malloc (sizeof(int));
			b = malloc (sizeof(int));
	
			/// TODO : CHANGE THIS TO A FUNCTION POINTER
			/// THAT POINT TO A FUNCTION THAT CONVERTS
			/// STRING TO THE CORRECT NUMERICAL TYPE.
			tmplf = atof (argv[2]);
			memcpy (a, &tmplf, sizeof(int));

			tmplf = atof (argv[3]);
			memcpy (b, &tmplf, sizeof(int));
		break;

		case 'c':
		case 'a':
			tmpc = 0;

			a = malloc (sizeof(char));
			b = malloc (sizeof(char));
	
			/// TODO : CHANGE THIS TO A FUNCTION POINTER
			/// THAT POINT TO A FUNCTION THAT CONVERTS
			/// STRING TO THE CORRECT NUMERICAL TYPE.
			tmpc = (argv[2][0]);
			memcpy (a, &tmpc, sizeof(char));

			tmpc = (argv[3][0]);
			memcpy (b, &tmpc, sizeof(char));
		break;
		}


	}

	if (compare)
	{
		result = compare (a, b);
		printf("compare (%s, %s) = %d\n\n", argv[2], argv[3], result);
	}
	*/

	if (map)
		free (map);
	if (a)
		free (a);
	if (b)
		free (b);
	
	return 0;
}
