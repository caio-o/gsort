#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "gsconfig.h"
#include "compare.h"
#include "treatargs.h"

//#include "test-t.h"
#define MAP_SIZE 256

struct GlobalConfig globalConf;

int main(int argc, char** argv)
{
	int (**map)    (const void*, const void*);
	int i;

	void *a = NULL;
	void *b = NULL;

	globalConf.iFile               =  NULL;
	globalConf.oFile               =  NULL;
	globalConf.ifpath              =  NULL;
	globalConf.ofpath              =  NULL;

	globalConf.inFileCount         =  0;
	globalConf.verbosity           =  0;
	globalConf.separator           =  ' ';
	
	globalConf.compare             =  BIT_FALSE;
	globalConf.silent              =  BIT_TRUE;
	globalConf.ignoreloc           =  BIT_TRUE;
	globalConf.exitOnFileError     =  BIT_TRUE;
	globalConf.unspecifiedOutFile  =  BIT_FALSE;

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

	printConfig (globalConf);

	if (map)
		free (map);
	if (a)
		free (a);
	if (b)
		free (b);
	
	return 0;
}
