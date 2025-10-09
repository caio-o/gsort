#include <stdio.h>
#include <unistd.h>     /// POSIX-EXCLUSIVE header
#include "treatargs.h"  
#include "test.h"

int treatArgs (int argc, char** argv)
{
	int option;

	do {
		option = getopt (argc, argv, OPT_LIST_ALL);

		printf ("\ngot option: ");
		
		switch (option) {
		case OPT_FILEPATH:
			printf ("file path");
		break;

		case OPT_NUMS:
			printf ("numbers");
		break;
		
		case OPT_TEST:
			printf ("test\n");
			test();
		break;

		case 'a':
			printf ("alpha");
		break;

		case 'c':
			printf ("char");
		break;

		case 'd':
			printf ("double");
		break;

		case 'i':
			printf ("integer");
		break;
		
		case 'f':
			printf ("float");
		break;
		}

	} while (option != -1);
	printf ("\n");

	return 0;
}

