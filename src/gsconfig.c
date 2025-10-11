#include <stdio.h>
#include "gsconfig.h"

int printConfig (const struct GlobalConfig conf)
{
	int result = (conf.ifpath != NULL && conf.ofpath != NULL);
	int i;

	printf ("Sorting\n");
	printf ("Output file:  %s\n", conf.ofpath);

	if (conf.ifpath) {
		printf ("Input files: ");
		for (i = 0; i < conf.inFileCount && !result; i++) {
			if (conf.ifpath[i])
				printf("%s ", conf.ifpath[i]);
			else {
				perror ("printConfig: NULL filepath taken");
				result = 1;
			}
		}

		printf ("\n");
	}


	if (conf.verbosity >= 1) {
		printf (
		"verbosity:          %d\n"
		"compare:            %u\n"
		"silent:             %u\n"
		"ignoreloc:          %u\n"
		"exitOnFileError:    %u\n"
		"unspecifiedOutFile: %u\n\n",
		conf.verbosity,
		conf.compare,
		conf.silent,
		conf.ignoreloc,
		conf.exitOnFileError,
		conf.unspecifiedOutFile);
	}

	return result;
}

