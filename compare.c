
#include "compare.h"
#include <ctype.h>
#include <math.h>


int intcmp (const void* a, const void* b)
{
        return *((int*)a) - *((int*)b);
}

int dblcmp (const void* a, const void*b)
{
	double diff = *((double*)a) - *((double*) b);
	
	return diff > 0.0  ?  ceil (diff)  :  floor (diff);
}

int floatcmp (const void* a, const void* b)
{
	float diff = *((float*)a) - *((float*) b);
	
	return diff > 0.0F  ?  ceil (diff)  :  floor (diff);
}

int charcmp (const void* a, const void* b)
{
	return *((char*) a) - *((char*) b);
}

int alphacmp (const void* a, const void* b)
{
        return tolower(*((char*)a)) - tolower(*((char*)b));
}

/*int lintcmp (const void* a, const void* b)
{
        return *((int*)a) - *((int*)b);
}

int floatcmp (const void* a, const void* b)
{
        return *((int*)a) - *((int*)b);
}

int doublecmp (const void* a, const void* b)
{
        return *((int*)a) - *((int*)b);
}

int stringcmp (const void* a, const void* b)
{
        return *((int*)a) - *((int*)b);
}


int ilycmp (const void* a, const void* b)
{
	//stuff

        return *((int*)a) - *((int*)b);
}*/

