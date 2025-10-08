
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "test.h"
#include "compare.h"
#include "sort-t.h"

#define TEST_SIZE 100

int test (void) {
	int i;
	int *v = (int*) malloc (sizeof (int) * TEST_SIZE);

	srand (time (NULL));

	if (v) {
		printf("\n\n");

		for (i = 0; i < TEST_SIZE; i++) {
			v[i] = random() % 1000;
			printf ("%d ", v[i]);
		}

		printf ("\n\n");
		fgetc (stdin);
		
		bubble_sort (v, TEST_SIZE, sizeof (int), intcmp);

		fgetc (stdin);

		for (i = 0; i < TEST_SIZE; i++) {
			printf ("%d ", v[i]);
		}

	}
	else {
		perror ("test");
		exit (1);
	}

	return 0;
}
