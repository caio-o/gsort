#include <stdio.h>
#include <unistd.h>     /// POSIX-EXCLUSIVE header
#include "main.h"
#include "treatargs.h"  
#include "test.h"

int treatArgs (int argc, char** argv)
{
	int option;

	do {
		option = getopt (argc, argv, OPT_LIST_ALL);

		switch (option) {
		case OPT_FILEPATH:
			globalConf.ofpath = strdup (optarg);	
			break;
		
		case OPT_VERBOSE:
			globalConf.verbosity++;
			break;

		case OPT_NUMS:
			printf ("numbers: %s", optarg);
			break;
		
		case OPT_TEST:
			printf ("test\n");
			test();
			break;

		case 'a':
			printf ("type: alpha");
			break;

		case 'c':
			printf ("type: char");
			break;

		case 'd':
			printf ("type: double");
			break;

		case 'i':
			printf ("type: integer");
			break;
		
		case 'f':
			printf ("type: float");
			break;
		}

	} while (option != -1);
	printf ("\n");

	globalConf.unspecifiedOutFile = 
		!(globalConf.ofpath && strlen (globalConf.ofpath) >= 1);

	return 0;
}

