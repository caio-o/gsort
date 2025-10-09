
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "test.h"
#include "compare.h"
#include "sort-t.h"

#define TEST_SIZE 100

int test (void) {
	int i;
	int *v = (int*) malloc (sizeof (int) * TEST_SIZE);
	char str[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

	srand (time (NULL));

	if (v) {
		printf("\n\n");

		printf ("Letras embaralhadas: %s\n", str);

		printf ("Numeros embaralhados:\n");
		for (i = 0; i < TEST_SIZE; i++) {
			v[i] = random() % 1000;
			printf ("%d ", v[i]);
		}

		printf ("\n\nAperte enter para desembaralhar\n\n");
		fgetc (stdin);
		
		bubble_sort (str, strlen(str), 1, charcmp);
		bubble_sort (v, TEST_SIZE, sizeof (int), intcmp);

		printf ("Letras desembaralhadas: %s\n", str);
		printf ("\nNumeros desembaralhados:\n");

		for (i = 0; i < TEST_SIZE; i++) {
			printf ("%d ", v[i]);
		}
		printf ("\n\n");
	}
	else {
		perror ("test");
		exit (1);
	}

	return 0;
}
