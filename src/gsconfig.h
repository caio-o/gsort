#ifndef __GSCONFIG_H
#define __GSCONFIG_H

#define  BIT(x)     unsigned int x:1

#define  BIT_TRUE   1U
#define  BIT_FALSE  0U

struct operation;

struct operation {
	int (*func) (FILE*, FILE*);

	struct operation* next;
};

struct oplist {
	struct operation* first;
	struct operation* curr;
	struct operation* last;
};

struct GlobalConfig {
	FILE**  iFile;
	FILE*   oFile;
	char**  ifpath;
	char*   ofpath;

	int     inFileCount;
	int     verbosity;
	char    separator;

	/* Boolean fields. Keep as last fields. */
	BIT     (compare);
	BIT     (silent);
	BIT     (ignoreloc);
	BIT     (exitOnFileError);
	BIT     (unspecifiedOutFile);
};

int printConfig (struct GlobalConfig conf);

#endif
